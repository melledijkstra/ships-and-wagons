package ui

import (
	"fmt"
	"ships-and-wagons/shared/game"
	"ships-and-wagons/shared/trade"
)

func DisplayMarketPrices(market *game.Market) {
	fmt.Printf("Market prices in %s:\n", market.TownName)
	for resource, price := range market.Prices {
		fmt.Printf("%s: %.2f\n", resource, price)
	}
}

func DisplayTradeRoutes(trades []trade.Trade) {
	fmt.Println("Trade routes:")
	for _, trade := range trades {
		fmt.Printf("From %s to %s by %s\n", trade.Route.StartTown, trade.Route.EndTown, trade.Route.Method)
		fmt.Printf("\tDuration left: %s\n", trade.DurationLeft())
	}
}

func DisplayPlayerInventory(player *game.Player) {
	fmt.Printf("%s's inventory:\n", player.Name)
	for resource, quantity := range player.Inventory {
		fmt.Printf("%s: %d\n", resource, quantity)
	}
}

func DisplayTrade(trade *trade.Trade) {
	fmt.Printf("Trade %d:\n", trade.ID)
	fmt.Printf("\tPlayer: %s\n", trade.PlayerName)
	fmt.Printf("\tStatus: %s - traveling by %s\n", trade.Status, trade.Route.Method)
	fmt.Printf("\tStart: %s - time left: %s\n", trade.StartTime, trade.DurationLeft())
}
