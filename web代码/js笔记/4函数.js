// //函数
// function addNums(num1=2,num2=1)//默认值
// {
//     console.log(num1+num2);
//     return num1+num2;
// }
// const a=addNums(2,3);
// console.log(`a=${a}`);

//lambda表达式
//const addNums = num1=> num1+5;
const addNums = (num1,num2) =>num1+num2;
console.log(addNums(5,3));