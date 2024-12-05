package test

import (
	"ships-and-wagons/shared/game"
	"testing"
)

func TestNewPlayer(t *testing.T) {
	name := "John"
	player := game.NewPlayer(name)

	if player.Name != name {
		t.Errorf("Expected player name to be %s, but got %s", name, player.Name)
	}

	if player.Money != 1000 {
		t.Errorf("Expected player money to be 0, but got %d", player.Money)
	}

	if player.Inventory == nil {
		t.Error("Expected player inventory to be initialized, but got nil")
	}
}
