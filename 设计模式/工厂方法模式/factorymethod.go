package factorymethod

// 稳定的
// 抽象类
type Operator interface {
	SetA(int)
	SetB(int)
	Result() int
}

// 工厂基类
type OperatorFactory interface {
	Create() Operator
}

// 公用方法
type OperatorBase struct {
	a, b int
}
func (o *OperatorBase) SetA(a int) {
	o.a = a
}
func (o *OperatorBase) SetB(b int) {
	o.b = b
}

// 变化的
// PlusOperator 的工厂类
type PlusOperatorFactory struct{}
func (PlusOperatorFactory) Create() Operator {
	return &PlusOperator{
		OperatorBase: &OperatorBase{},
	}
}
// 加法实现
type PlusOperator struct {
	*OperatorBase
}
func (o PlusOperator) Result() int {
	return o.a + o.b
}

// MinusOperator 的工厂类
type MinusOperatorFactory struct{}
func (MinusOperatorFactory) Create() Operator {
	return &MinusOperator{
		OperatorBase: &OperatorBase{},
	}
}
// 减法实现
type MinusOperator struct {
	*OperatorBase
}
func (o MinusOperator) Result() int {
	return o.a - o.b
}
