package abstractfactory

import (
    "fmt"
)

// 稳定
// OrderMainDAO 为订单主记录
type OrderMainDAO interface {
	SaveOrderMain()
}
// OrderDetailDAO 为订单详情纪录
type OrderDetailDAO interface {
	SaveOrderDetail()
}
// DAOFactory DAO 抽象模式工厂接口
type DAOFactory interface {
	CreateOrderMainDAO() OrderMainDAO
	CreateOrderDetailDAO() OrderDetailDAO
}

// 第一种变化
// RDBMainDAP 为关系型数据库的OrderMainDAO实现
type RDBMainDAO struct{}
func (*RDBMainDAO) SaveOrderMain() {
	fmt.Print("rdb main save\n")
}
// RDBDetailDAO 为关系型数据库的OrderDetailDAO实现
type RDBDetailDAO struct{}
func (*RDBDetailDAO) SaveOrderDetail() {
	fmt.Print("rdb detail save\n")
}
// RDBDAOFactory 是RDB 抽象工厂实现
type RDBDAOFactory struct{}
func (*RDBDAOFactory) CreateOrderMainDAO() OrderMainDAO {
	return &RDBMainDAO{}
}
func (*RDBDAOFactory) CreateOrderDetailDAO() OrderDetailDAO {
	return &RDBDetailDAO{}
}

// 第二种变化
// XMLMainDAO XML存储
type XMLMainDAO struct{}
func (*XMLMainDAO) SaveOrderMain() {
	fmt.Print("xml main save\n")
}
// XMLDetailDAO XML存储
type XMLDetailDAO struct{}
func (*XMLDetailDAO) SaveOrderDetail() {
	fmt.Print("xml detail save")
}

// XMLDAOFactory 是RDB 抽象工厂实现
type XMLDAOFactory struct{}
func (*XMLDAOFactory) CreateOrderMainDAO() OrderMainDAO {
	return &XMLMainDAO{}
}
func (*XMLDAOFactory) CreateOrderDetailDAO() OrderDetailDAO {
	return &XMLDetailDAO{}
}
