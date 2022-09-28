package main

import "fmt"
import "os"
import "os/exec"
import "syscall"

func main() {
	PS, err := exec.LookPath("ps")
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(PS)
	command := []string{"ps", "-a", "-x"}
	env := os.Environ()
	err = syscall.Exec(PS, command, env)

	if err != nil {
		fmt.Println(err)
	}
}