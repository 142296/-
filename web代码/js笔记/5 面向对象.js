//对象
function Girlfriend(name,height,dob,lod){   //有属性和方法
    this.name=name;
    this.height=height;
    this.dob = new Date(dob);           //调用日期函数
    this.lod = new Date(lod);
    const t= Date.now();
    const now =new Date(t);
    console.log(now);
    this.getLoveDays = function(){
        return now.Date-lod.Date;
    }
}
    Girlfriend.prototype.getnow = function(){       //方法也可以卸载对象外面
        return `${this.lod}`;
    }

const Girlfriend1=new Girlfriend('coke','158','2002.4.7 13:00','2020.11.30');

console.log(Girlfriend1.dob);
console.log(Girlfriend1.getLoveDays());
console.log(Girlfriend1.getnow());