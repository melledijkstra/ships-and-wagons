package game

type Market struct {
    TownName  string
    Inventory map[string]int
    Prices    map[string]float64
}

func NewMarket(townName string) *Market {
    return &Market{
        TownName:  townName,
        Inventory: make(map[string]int),
        Prices:    make(map[string]float64),
    }
}

func (m *Market) UpdatePrices() {
    // Logic to update prices based on supply and demand
}
