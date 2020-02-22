package main

import (
    "fmt"
)

type test interface {
    printTest1()
    printTest2()
}

type Test struct{}
func (Test)printTest1() {
    fmt.Println("printTest1()")
}
func (Test)printTest2() {
    fmt.Println("printTest2()")
}

func main() {
    t := Test{}
    t.printTest1()
    t.printTest2()
}
