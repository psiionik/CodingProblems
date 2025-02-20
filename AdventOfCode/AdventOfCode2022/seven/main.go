package main

import (
	"bufio"
	"fmt"
	"os"
)

func recursiveDescent(list_of_commands []string, directory_map map[string]int) {
	fmt.Println(list_of_commands[0])
}

func processCommands(list_of_commands []string) {
	directory_map := make(map[string]int, 1)
	directory_map["/"] = 0

	recursiveDescent(list_of_commands[1:], directory_map)
}

// Part One
func main() {

	debug := false

	if len(os.Args) == 2 {
		if os.Args[1] == "debug" {
			debug = true
		}
	}

	var readFile *os.File
	var err error

	if debug {
		readFile, err = os.Open("sample.txt")
	} else {
		readFile, err = os.Open("input.txt")
	}

	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	list_of_commands := make([]string, 0)

	fileScanner := bufio.NewScanner(readFile)
	fileScanner.Split(bufio.ScanLines)
	for fileScanner.Scan() {
		token := fileScanner.Text()

		list_of_commands = append(list_of_commands, token)
	}
	readFile.Close()

	processCommands(list_of_commands)
}
