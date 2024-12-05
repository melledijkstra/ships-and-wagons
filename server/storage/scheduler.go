package storage

import (
	"ships-and-wagons/shared/trade"
	"time"
)

func StartTrade(t trade.Trade) {
	go func(trde trade.Trade) {
		time.Sleep(trde.Route.Duration)
		trde.Status = "Completed"
		UpdateTradeStatus(trde.ID, "Completed")
		// Notify player of trade completion
	}(t)
}

func ResumeTrades() {
	trades, err := LoadTrades()
	if err != nil {
		panic(err)
	}

	for _, trade := range trades {
		elapsed := time.Since(trade.StartTime)
		remaining := trade.Route.Duration - elapsed
		if remaining > 0 {
			StartTrade(trade)
		} else {
			trade.Status = "Completed"
			UpdateTradeStatus(trade.ID, "Completed")
			// Notify player of trade completion
		}
	}
}
