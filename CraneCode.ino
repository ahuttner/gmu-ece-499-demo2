#define BaseS 1
#define CartS 2
#define LevelS 3
#define GripS 4
#define Open 300
#define Large 250
#define Medium 200
#define Small 150

char i = 's';
int Base = 0;
int Cart = 0;
int Level = 0;
int Grip = 0;

Dynamixel Dxl(1);

void setup(){
  Dxl.begin(3);
  Dxl.wheelMode(BaseS);
  Dxl.wheelMode(CartS);
  Dxl.wheelMode(LevelS);
  Dxl.jointMode(GripS);
  SerialUSB.attachInterrupt(usbInterrupt);
}

void usbInterrupt(byte* buffer, byte nCount){
  
  i =(char)buffer[0];  
    SerialUSB.println(i);
    
  switch (i) {
    
    //Stop
    case 's':
      Base = 0;
      Cart = 0;
      Level = 0;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
      
    //Rotate Left
    case 'a':
      Base = 100;
      Cart = 0;
      Level = 0;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
      
      //Rotate Right
    case 'd':
      Base = 100 | 0x400;
      Cart = 0;
      Level = 0;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
      
      //Cart Forward
    case 'w':
      Base = 0;
      Cart = 100;
      Level = 0;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
      
    //Cart Reverse
    case 'e':
      Base = 0;
      Cart = 100 | 0x400;
      Level = 0;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;

    //Gripper Down
    case 'f':
      Base = 0;
      Cart = 0;
      Level = 100;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
      
    //Gripper Up
    case 'r':
      Base = 0;
      Cart = 0;
      Level = 100 | 0x400;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
      
    //Gripper Open
    case 'q':
      Base = 0;
      Cart = 0;
      Level = 0;
      Grip = Open;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;

    //Gripper Close Large
    case '1':
      Base = 0;
      Cart = 0;
      Level = 0;
      Grip = Large;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;      

    //Gripper Close Medium
    case '2':
      Base = 0;
      Cart = 0;
      Level = 0;
      Grip = Medium;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;  
      
    //Gripper Close Small
    case '3':
      Base = 0;
      Cart = 0;
      Level = 0;
      Grip = Small;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;  
      
    //Default to stop
    default:
      Base = 0;
      Cart = 0;
      Level = 0;
      SerialUSB.print("Base speed:");
      SerialUSB.println(Base);
      SerialUSB.print("Cart speed:");
      SerialUSB.println(Cart);
      SerialUSB.print("Level speed:");
      SerialUSB.println(Level);
      break;
  }
}

void loop(){
  delay(100);
  Dxl.goalSpeed(BaseS,Base);
  Dxl.goalSpeed(CartS,Cart);
  Dxl.goalSpeed(LevelS,Level);
  Dxl.goalPosition(GripS,Grip);  
}


