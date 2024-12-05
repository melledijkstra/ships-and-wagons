package trade

import (
	"ships-and-wagons/shared/game"
	"time"
)

func TradeGoods(player *game.Player, market *game.Market, resourceName string, quantity int, action string) {
	if action == "buy" {
		totalCost := market.Prices[resourceName] * float64(quantity)
		if player.Money >= int(totalCost) && market.Inventory[resourceName] >= quantity {
			player.Money -= int(totalCost)
			player.Inventory[resourceName] += quantity
			market.Inventory[resourceName] -= quantity
		}
	} else if action == "sell" {
		totalEarnings := market.Prices[resourceName] * float64(quantity)
		if player.Inventory[resourceName] >= quantity {
			player.Money += int(totalEarnings)
			player.Inventory[resourceName] -= quantity
			market.Inventory[resourceName] += quantity
		}
	}
}

type TradeRoute struct {
	StartTown  string
	EndTown    string
	Method     string // "Ship" or "Wagon"
	Duration   time.Duration
	RiskFactor float64
}

type Trade struct {
	ID         int
	PlayerName string
	Route      TradeRoute
	StartTime  time.Time
	Status     string // "InProgress" or "Completed"
}

func (t *Trade) DurationLeft() time.Duration {
	elapsedTime := time.Since(t.StartTime)
	remainingTime := t.Route.Duration - elapsedTime
	return remainingTime
}

func GetTrades() []Trade {
	var trades = []Trade{
		{
			ID:         1,
			PlayerName: "Player1",
			Route:      TradeRoute{"Town1", "Town2", "Ship", time.Hour * 2, 0.1},
			StartTime:  time.Now().Add(-time.Hour),
			Status:     "InProgress",
		},
		{
			ID:         2,
			PlayerName: "Player2",
			Route:      TradeRoute{"Town1", "Town3", "Wagon", time.Hour * 3, 0.2},
			StartTime:  time.Now().Add(-time.Hour * 2),
			Status:     "Completed",
		},
	}

	return trades
}

func GetTradeRoutes() []TradeRoute {
	// Example trade routes
	var tradeRoutes = []TradeRoute{
		{"Town1", "Town2", "Ship", time.Hour * 2, 0.1},
		{"Town1", "Town3", "Wagon", time.Hour * 3, 0.2},
		{"Town2", "Town3", "Ship", time.Hour * 1, 0.15},
	}

	return tradeRoutes
}
