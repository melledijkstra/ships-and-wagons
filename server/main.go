package main

import (
	"encoding/json"
	"log"
	"net/http"
	"ships-and-wagons/server/storage"
)

type Response struct {
	Message string `json:"message"`
}

func helloHandler(w http.ResponseWriter, r *http.Request) {
	response := Response{Message: "Hello, World!"}
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

func main() {
	log.Print("Opening connection to database...")
	// Initialize database
	storage.InitDB("saw.db")
	log.Println("done")

	// Resume unfinished trades
	storage.ResumeTrades()

	http.HandleFunc("/hello", helloHandler)
	log.Println("Starting server on :8080")

	if err := http.ListenAndServe(":8080", nil); err != nil {
		log.Fatalf("Could not start server: %s\n", err.Error())
	}
}
