package game

type Player struct {
    Name      string
    Money     int
    Inventory map[string]int
}

func NewPlayer(name string) *Player {
    return &Player{
        Name:      name,
        Money:     1000,
        Inventory: make(map[string]int),
    }
}
