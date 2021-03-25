// //数组   不限类型
// const number=new Array(1,2,3,4,5);
// const f=['apple','orange','pear',1322];
// f.push('banana');   //末项
// f.unshift('add')    //首项
// f.pop();            //弹出最后一项
// Array.isArray(f);     //判断是否为数组
// console.log(number);
// console.log(f[3]);


// //对象
// const person={
//     firstName:'john',
//     lastName:'Doe',
//     age:30,
//     hobbies:['music','movies','sports'], 
//     address:{
//         steet:'50 main st',
//         city:'Boston',
//         state:'Ma'
//     }
// }
// person.add=23;          //增添新元素
// console.log(person);

//数组对象
const todos=[
   {
       id:1,
       text:'Take out trash',
       isCompleted:true,
   }, 
   {
       id:2,
       text:'meeting with boss',
       isCompleted:true,
   },
   {
       id:3,
       text:'Dentist appt',
       isCompleted:false,
   }
];
//JSON          传给服务器
// const todoJSON =JSON.stringify(todos);
// console.log(todoJSON);

// //for循环新用法
// for(let i of todos)
// {
//     console.log(`id:${i.id}`);
// }


// //forEach
// todos.forEach(function(i)
// {
//     console.log(i.text);    
// });
//todos.forEach((todo) => console.log(todo));简写

////map     获得取值
// const todoText=todos.map(function(i)
// {
//     return i.text;
// })
// console.log(todoText);

// //filter        筛选
// const todoCompleted=todos.filter(function(todo)
// {
//     return todo.isCompleted===true;
//     "9527" == 9527  //返回true
//     "9527" === 9527 //返回false，因为两种数据的类型不同
// });
//console.log(todoCompleted);

// //filter+map        //获得筛选后的取值
// const todoCompleted=todos.filter(function(todo)
// {
//     return todo.isCompleted===true;
//     "9527" == 9527  //返回true
//     "9527" === 9527 //返回false，因为两种数据的类型不同
// }).map(function(todo){
//     return todo.text;
// })
// console.log(todoCompleted);