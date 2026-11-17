package java_code;

abstract class Car {
    int maxSpeed;   
    int exceed;     
    double speed;      
    int score=12; 
    int fine=0;   
    Car(int maxSpeed, int exceed){
        this.maxSpeed=maxSpeed;
        this.exceed=exceed;
    }
    abstract void stop();
    void setSpeed(int speed){
        this.speed=speed;
        System.out.println(getClass().getSimpleName()+" current speed:" + speed + " miles per hour");
        if(speed>exceed){
            score-=1;
            fine+=200;
            System.out.println("超速!扣1分积分,罚款200元.（剩余积分：" + score + "，累计罚款：" + fine + "元）");
        }
        stop();
    }
}

class Ford extends Car{
    Ford(int maxSpeed, int exceed) {
        super(maxSpeed, exceed);
    }
    @Override
    void stop() {
        if(speed>200){
            System.out.println("Ford 车速超过200公里/小时，停车！");
        }
    }
}

class QQ extends Car{
    QQ(int maxSpeed, int exceed) {
        super(maxSpeed, exceed);
    }
    @Override
    void stop(){
        if(speed>150){
            System.out.println("QQ 车速超过150公里/小时，停车！");
        }
    }
}

public class CarTest {
    public static void main(String[] args) {
        Car ford=new Ford(240, 120);
        Car qq=new QQ(160, 100);
        ford.setSpeed(100);  
        ford.setSpeed(150);   
        ford.setSpeed(210);   
        qq.setSpeed(80);     
        qq.setSpeed(120);    
        qq.setSpeed(155); 
    }
}