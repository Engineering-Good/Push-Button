////////////////////////////////////ONLY CHANGE VARIABLES HERE//////////////////////////////////////////////////////
int minNum = 2;     //Sets the minimum number in the range of the random variable
int maxNum = 10;    //Sets the maximum number in the range of the random variable
int timeInt = 3000; //Sets the time (in milliseconds; 3000 milliseconds is 3 seonds) for which the toy will operate 
///////////////////////////////////DO NOT CHANGE ANYTHING BELOW UNLESS YOU KNOW WHAT YOU WANT///////////////////////


const int button = 8; 
const int Relay_Pin = 7;
int offState = 0;
int count=0;
int randNum;
int buttonStat=1;
int prevButtonStat=1;

void setup(){
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(Relay_Pin,OUTPUT);
}

void loop(){

  if (count==0)
  {
    randNum=random(minNum,maxNum);
  }
  else
  {
    randNum=randNum;
  }
  
  buttonStat = digitalRead(button);//Reads BUTTON reading

  delay(50); //just here to slow down the output for easier reading
  if (offState == 0)
  {
    if (prevButtonStat == 0 && buttonStat == 0)
    {
      digitalWrite(Relay_Pin,HIGH);
      delay(50);
    }
    else if (prevButtonStat == 0 && buttonStat == 1)
    {
      digitalWrite (Relay_Pin,LOW);
      delay(timeInt);
      count=count+1;
    }
    else
    {
      digitalWrite(Relay_Pin,LOW);
      
    }
  }
  else
  {
    digitalWrite(Relay_Pin,HIGH);
  }

  prevButtonStat = buttonStat;//store current force reading as the past reading 

  if (count == randNum)
  {
    offState=1;
  }
}
