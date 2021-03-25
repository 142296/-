import random
class game:
        x=random.randint(0,10)
        y=random.randint(0,10)
        Life_value=100
        class Tortoise:
                def move(self):
                        select=random.randint(0,3)
                        pace=random.randint(1,2)
                        if select in [0,1] and 0<=self.x+pace*-1**select<=10:
                                self.x+=pace*-1**select
                                self.Life_value-=1
                        else:
                                Tortoise.move(self)
                        if select in [2,3] and 0<=self.y+pace*-1**select<=10:
                                self.y+=pace*-1**select
                                self.Life_value-=1
                        else:
                                Tortoise.move(self)
                
        class fish1:
                i=random.randint(0,10)
                j=random.randint(0,10)
                def move(self):
                        select=random.randint(0,3)
                        if select in [0,1] and 0<=self.i+-1**select<=10:
                                self.i+=-1**select
                                if self.i==self.x and self.j==self.y:
                                        self.Life_value+=20
                                        if  self.Life_value>100:
                                                 self.Life_value=100
                                                
                        else:
                                fish1.move(self)
                        if select in [2,3] and 0<=self.j+-1**select<=10:
                                self.j+=-1**select
                                if self.i==self.x and self.j==self.y:
                                        self.Life_value+=20
                                        if  self.Life_value>100:
                                                 self.Life_value=100
                                        
                        else:
                                fish1.move(self)
        class fish2(fish1):
                pass
        class fish3(fish1):
                pass
        class fish4(fish1):
                pass
        class fish5(fish1):
                pass
        class fish6(fish1):
                pass
        class fish7(fish1):
                pass
        class fish8(fish1):
                pass
        class fish8(fish1):
                pass
        class fish9(fish1):
                pass
        class fish10(fish1):
                pass
