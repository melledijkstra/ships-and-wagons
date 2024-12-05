package main

import (
	"fmt"
	"ships-and-wagons/client/ui"
	"ships-and-wagons/shared/game"
	"ships-and-wagons/shared/trade"
	"time"
)

func main() {
	fmt.Println("Welcome to the Trading Game!")

	// Initialize game entities
	player := game.NewPlayer("Alice")
	market := game.NewMarket("Town1")
	market.Prices["wood"] = 10
	market.Inventory["wood"] = 100

	// Example game flow
	ui.DisplayMarketPrices(market)
	trade.TradeGoods(player, market, "wood", 10, "buy")
	ui.DisplayPlayerInventory(player)

	time.Sleep(2 * time.Second)

	routes := trade.GetTrades()
	// PENDING: get routes from api
	// routes, err := api.FetchTrades()
	// if err != nil {
	// 	panic(err)
	// }

	ui.DisplayTradeRoutes(routes)

	// Example: Starting a new trade
	route := trade.GetTradeRoutes()[1]
	trade := &trade.Trade{
		PlayerName: player.Name,
		Route:      route,
		StartTime:  time.Now(),
		Status:     "InProgress",
	}

	ui.DisplayTrade(trade)
}
