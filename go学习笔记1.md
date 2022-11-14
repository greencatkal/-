#2022.10.30-2022.11.6笔记
---
##1.go语言的优点及特性
- >更少的编译时间
- >自动回收“垃圾”
- >函数可以返回多个值
- >语言可交互性
- >类与接口编程
##2.go语言的组成
> 1.包声明
```go
package main
```
定义包名为main[^1]
[^1]:其文件名和包名没有必然联系，不会互相干扰，不必要统一名称，但同一文件夹下的多文件中只能有一个包名。
> 2.引入包
```go
import "fmt"
```
等价于告诉go编译器运行这个程序需要使用fmt包里的函数或其他元素
> 3.函数
```go
func main(){(函数体)}
```
类似于c语言，程序必须包含一个main函数
> 4.变量、语句&表达式

> 5.注释

go语言中的注释与c中相同，”//“引出单行注释，”/* ......... */“引出多行注释
###一段完整的go代码
```go
package main
import "fmt"
func main(){//注意此处左大括号不能单起一行
    fmt.Println("Hello,world!")
}
```
###运行结果
> Hello,world!

##3.Go基本语法
> 1.行分隔符
```go
fmt.Println("Hello,World!")
```
go语言规定一行代表一个语句结束，它不需要像c语言一样以分号结尾
> 2.标识符

标识符用来命名变量、类等程序元素，其命名规范与c一致：第一个字符必须是下划线或字母，标识符不可以与go语言关键字冲突
> 3.数据类型

>> 1.布尔型(bool)

布尔型结果只能为false或true
```go
var b bool = true
```
>> 2.数字型

整型int与浮点型float；特别地，go语言支持复数型complex
>> 3.字符串类型

由单个字节连接起来的字符串
>> 4.派生型  

指针、数组、结构体、函数、Channel、切片、接口、Map
##3.go语言变量
###1.变量声明
> 最标准式

变量声明一般形式会使用var关键字，例如下一最标准的形式<声明> <变量名> <变量类型> = <值>
```go
var identifier string="ppap"
```
> 同时声明多个变量赋多值

可以一次声明多个变量
```go
var ident1,ident2 string="ppap","dedd"
```
> 声明类型但不赋值

以上变量声明且初始化，也可以如下声明但不初始化，变量默认为其类型的默认值(int-0;string-"";bool-false)
```go
var age int //age="0"
var a *int //a=nil(空指针)
var b []int //b=nil(空数组)
```
> 赋值但不声明类型

编译器会根据输入的值自行判断变量类型
```go
var name="Bob" //string型
```
> := 便利型

此种形式可以省去声明var和变量类，全部交由编译器自行判断；
```go
a:=3 //等价于var a int =3;
a,b,c:=2,5,"abc" //a=2,b=5,c="abc"
```
###2.常量声明
> 标准定义格式
```go
const ident string="abc"
```
类似地，也可省去常量类型
```go
const a,b=1,"ab"
```
###3.运算符
> 1.算术运算符

go语言与c语言运算符基本一致
>2.条件句

go语言与c语言条件句基本相符，包括if;if...else;if嵌套;switch,select等；
但要注意，go语言没有三目运算符，不支持?:的判断。
>3.循环句

go语言与c语言循环句基本相符，但没有while式循环；
go语言的循环控制语句（break,continue,goto）与c作用相当。
##4.函数
>1.定义函数

go函数定义格式如
<声明> <函数名> <参数及其类型> <返回值类型> {
    （函数体）
}
```go
func name (a int) int {
    b := 2
    b *= a
    return b
}
```
其中，函数参数及其类型可以被省略，特别地，当函数不需要返回值时，可以省略返回值类型
>2.调用函数

go的函数调用与c语言一致
```go
package main

import "fmt"

func main() {
   /* 定义局部变量 */
   var a int = 100
   var b int = 200
   var ret int

   /* 调用函数并返回最大值 */
   ret = max(a, b)

   fmt.Printf( "最大值是 : %d\n", ret )
}

/* 函数返回两个数的最大值 */
func max(num1, num2 int) int {
   /* 定义局部变量 */
   var result int

   if (num1 > num2) {
      result = num1
   } else {
      result = num2
   }
   return result
}
```
>3.多值返回

go语言函数能返回多个值
```go
func swap(x, y string) (string, string) {
   return y, x
}
```
>4.参数传递形式

go语言只有两种参数传递方式：值传递与引用传递，默认情况下函数使用值传递形式，并且函数本身也可以被另一个函数当作参数使用
##5.数组与切片
###1.数组
go语言中数组与c语言中原理相同
>声明数组

与变量的声明类似
```go
var name [4] int{100,10,1,0}
name := [4] int{100,10,10,0}
name := [...] int{100,10,10,0}
```
>多维数组

go语言支持多维数组

###2.切片
>1.定义

Go 语言切片是对数组的抽象。
Go 数组的长度不可改变，在特定场景中这样的集合就不太适用，Go 中提供了一种灵活，功能强悍的内置类型切片(相当于"动态数组")，与数组相比切片的长度是不固定的，可以追加元素，在追加时可能使切片的容量增大。
>2.定义切片

可以使用make函数来定义切片
```go
var slice []int = make([]int, len)//最标准
slice1 := make([]int,len)//:=式
```
>3.初始化切片

直接初始化
```go
s :=[] int {1,2,3}
s := arr[:] //s是arr的引用
s := arr[a:b] // 从数组arr下标a-b创建一个新切片,不输入a或b时即从最开始到b或a到最后一个元素
s := []int //空切片
-----