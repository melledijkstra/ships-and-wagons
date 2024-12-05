package storage

import (
	"database/sql"
	"ships-and-wagons/shared/trade"
	"time"

	_ "github.com/mattn/go-sqlite3"
)

var db *sql.DB

func InitDB(filepath string) {
	var err error
	db, err = sql.Open("sqlite3", filepath)
	if err != nil {
		panic(err)
	}

	createTableIfNotExists()
}

func createTableIfNotExists() {
	createTableSQL := `
	CREATE TABLE IF NOT EXISTS trades (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			player_name TEXT NOT NULL,
			start_town TEXT NOT NULL,
			end_town TEXT NOT NULL,
			method TEXT NOT NULL,
			duration INTEGER NOT NULL,
			start_time DATETIME NOT NULL,
			status TEXT NOT NULL
	);
	`
	_, err := db.Exec(createTableSQL)
	if err != nil {
		panic(err)
	}
}

func SaveTrade(trade trade.Trade) error {
	_, err := db.Exec(
		"INSERT INTO trades (player_name, start_town, end_town, method, duration, start_time, status) VALUES (?, ?, ?, ?, ?, ?, ?)",
		trade.PlayerName, trade.Route.StartTown, trade.Route.EndTown, trade.Route.Method, trade.Route.Duration.Seconds(), trade.StartTime, trade.Status)
	return err
}

func LoadTrades() ([]trade.Trade, error) {
	rows, err := db.Query("SELECT player_name, start_town, end_town, method, duration, start_time, status FROM trades WHERE status = 'InProgress'")
	if err != nil {
		return nil, err
	}
	defer rows.Close()

	trades := []trade.Trade{}
	for rows.Next() {
		var trade trade.Trade
		var duration float64
		err := rows.Scan(&trade.PlayerName, &trade.Route.StartTown, &trade.Route.EndTown, &trade.Route.Method, &duration, &trade.StartTime, &trade.Status)
		if err != nil {
			return nil, err
		}
		trade.Route.Duration = time.Duration(duration) * time.Second
		trades = append(trades, trade)
	}
	return trades, nil
}

func UpdateTradeStatus(tradeID int, status string) error {
	_, err := db.Exec("UPDATE trades SET status = ? WHERE id = ?", status, tradeID)
	return err
}
