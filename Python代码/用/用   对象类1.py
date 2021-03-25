class Ticket:
        price=100
        adult=0
        child=0
        def __init__(self):             #自启动函数
                self.adult=int(input('成人'))
                self.child=int(input('儿童'))
                day=input('是否周末Y/N')
                if day=='Y':
                        Ticket.weekend(self)   #调用下面函数
                Ticket.total_price(self)        #调用下面函数
                
        def weekend(self):
                self.price=120
        def total_price(self):
                total_price=self.adult*self.price+(self.child*self.price)/2
                print(total_price)
                        
