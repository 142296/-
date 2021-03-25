
//1网页提醒与简便查错
alert("Hello World");   //网页提醒
console.log('Hello ');      //查错必备
console.error("error");     //*2
console.warn('warn');       //*3


//2变量  let变量 const常量
同C
类型String,Numbers,Boolean,null,undefined
let a="love";             //这样可以
                            这样也行
let a;
a="love3";
console.log(a);
let b=true    //Boolean类型
console.log(typeof a);      //获取类型


//3字符串
let a,b,c;
a="abcd";
b="efgh";
c=a+b+'123';                 //简单拼接
console.log(c);
                            //拼接2
c=`123 ${a} ${b}`;          //反引号在ESC下面
console.log(c);
c.length;                   //属性没有括号，方法有 
let d=c.split('f');         //拆分成数组(object)
console.log(d);
