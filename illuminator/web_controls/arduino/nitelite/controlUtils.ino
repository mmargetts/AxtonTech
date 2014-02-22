typedef struct {
  char* button_name;
  char* port_name;
  int  io_port;  
} IR_Button;

//define vars
String powerStatus1       = "off";
String powerStatus2       = "off";
String powerStatus3       = "off";
String buttonStatus11     = "off";
String buttonStatus21     = "ofF";
String buttonStatus31     = "off";
String buttonStatus12     = "off";
String buttonStatus22     = "ofF";
String buttonStatus32     = "off";
String buttonStatus13     = "off";
String buttonStatus23     = "ofF";
String buttonStatus33     = "off";
String dayNightStatus1    = "off";
String dayNightStatus2    = "off";
String dayNightStatus3    = "off";
String manualOff1         = "on";
String manualOff2         = "on";
String manualOff3         = "on";

int io_jumper_hybrid      = 22;
int io_jumper_zoom        = 26;
int io_jumper_xlr         = 30;

int io_jumper_illuminator1= 42;
int io_power1             = 45;
int io_day_night1         = 47;
int io_in31               = 49;
int io_in21               = 51;
int io_in11               = 53;

int io_jumper_illuminator2= 38;
int io_power2             = 33;
int io_day_night2         = 35;
int io_in32               = 37;
int io_in22               = 39;
int io_in12               = 41;


int io_jumper_illuminator3= 34;
int io_power3             = 23;
int io_day_night3         = 25;
int io_in33               = 27;
int io_in23               = 29;
int io_in13               = 31;



int pinInArrary[] = {io_jumper_illuminator1,io_jumper_illuminator2,io_jumper_illuminator3,io_power1,io_power2,io_power3,io_jumper_hybrid,io_jumper_zoom,io_jumper_xlr}; 
int pinOutArrary[]={io_in11,io_in21,io_in31,io_in12,io_in22,io_in32,io_in13,io_in23,io_in33}; 
int io_in1Arrary[]={io_in11,io_in21,io_in31};
int io_in2Arrary[]={io_in12,io_in22,io_in32};
int io_in3Arrary[]={io_in13,io_in23,io_in33};


void initPins()
{
      // set default pin modes
    for(int i=0;i<sizeof(pinInArrary)/sizeof(int);i++){
      pinMode(pinInArrary[i], INPUT_PULLUP);
    }

   for(int i=0;i<sizeof(pinOutArrary)/sizeof(int);i++){
      pinMode(pinOutArrary[i], OUTPUT);
      digitalWrite(pinOutArrary[i], HIGH);
    }
    pinMode(io_day_night1, OUTPUT);
    pinMode(io_day_night2, OUTPUT);
    pinMode(io_day_night3, OUTPUT);
    digitalWrite(io_day_night1,LOW);
    digitalWrite(io_day_night2,LOW);
    digitalWrite(io_day_night3,LOW);


}

void setManualOff(int io[]){
  for (int i = 0; i < (sizeof(io)/sizeof(int)) - 1; i++) {
    digitalWrite(io[i],HIGH);
  }
}


// checks if received HTTP request is switching on/off LEDs
// also saves the state of the LEDs
void SetDLs(void)
{
 // Serial.println(HTTP_req);
  
  if (digitalRead(io_power1)){
    powerStatus1="off";
  }else{powerStatus1="on";}

  if (StrContains(HTTP_req, "manualOff1=1")){
    setManualOff(io_in1Arrary);
    manualOff1      = "on";
    buttonStatus11  = "off";
    buttonStatus21  = "off";
    buttonStatus31  = "off";
  }else if (StrContains(HTTP_req, "button11=1")){
    Serial.println("***** button11 on ***");
    digitalWrite(io_in11,LOW);
    manualOff1     = "off";
    buttonStatus11 = "on";
  }else if (StrContains(HTTP_req, "button11=0")){
    Serial.println("***** button11 off ***");
    Serial.println(HTTP_req);
    digitalWrite(io_in11,HIGH);
    manualOff1     = "off";
    buttonStatus11 = "off";
  }else if (StrContains(HTTP_req, "button21=1")){
    digitalWrite(io_in21,LOW);
    manualOff1     = "off";
    buttonStatus21 = "on";
  }else if (StrContains(HTTP_req, "button21=0")){
    digitalWrite(io_in21,HIGH);
    manualOff1     = "off";
    buttonStatus21 = "off";
  }else if (StrContains(HTTP_req, "button31=1")){
    digitalWrite(io_in31,LOW);
    manualOff1     = "off";
    buttonStatus31 = "on";
  }else if (StrContains(HTTP_req, "button31=0")){
    digitalWrite(io_in31,HIGH);
    manualOff1     = "off";
    buttonStatus31 = "off";
  }else if (StrContains(HTTP_req, "dayNight1=1")){
    digitalWrite(io_day_night1,HIGH);
    dayNightStatus1 = "on";
  }else if (StrContains(HTTP_req, "dayNight1=0")){
    digitalWrite(io_day_night1,LOW);
    dayNightStatus1 = "off";
  }
  
  
  if (digitalRead(io_power2)){
    powerStatus2="off";
  }else{powerStatus2="on";}
  
  if (StrContains(HTTP_req, "manualOff2=1")){
    setManualOff(io_in2Arrary);
    manualOff2      = "on";
    buttonStatus12  = "off";
    buttonStatus22  = "off";
    buttonStatus32  = "off";
  }else if (StrContains(HTTP_req, "button12=1")){
    digitalWrite(io_in12,LOW);
    manualOff2     = "off";
    buttonStatus12 = "on";
  }else if (StrContains(HTTP_req, "button12=0")){
    digitalWrite(io_in12,HIGH);
    manualOff2     = "off";
    buttonStatus12 = "off";
  }else if (StrContains(HTTP_req, "button22=1")){
    digitalWrite(io_in22,LOW);
    manualOff2     = "off";
    buttonStatus22 = "on";
  }else if (StrContains(HTTP_req, "button22=0")){
    digitalWrite(io_in22,HIGH);
    manualOff2     = "off";
    buttonStatus22 = "off";
  }else if (StrContains(HTTP_req, "button32=1")){
    digitalWrite(io_in32,LOW);
    manualOff2     = "off";
    buttonStatus32 = "on";
  }else if (StrContains(HTTP_req, "button32=0")){
    digitalWrite(io_in32,HIGH);
    manualOff2     = "off";
    buttonStatus32 = "off";
  }else if (StrContains(HTTP_req, "dayNight2=1")){
    digitalWrite(io_day_night2,HIGH);
    dayNightStatus2 = "on";
  }else if (StrContains(HTTP_req, "dayNight2=0")){
    digitalWrite(io_day_night2,LOW);
    dayNightStatus2 = "off";
  }
  

  if (digitalRead(io_power3)){
    powerStatus3="off";
  }else{powerStatus3="on";}
  
  if (StrContains(HTTP_req, "manualOff3=1")){
    setManualOff(io_in3Arrary);
    manualOff3      = "on";
    buttonStatus13  = "off";
    buttonStatus23  = "off";
    buttonStatus33  = "off";
  }else if (StrContains(HTTP_req, "button13=1")){
    digitalWrite(io_in13,LOW);
    manualOff3     = "off";
    buttonStatus13 = "on";
  }else if (StrContains(HTTP_req, "button13=0")){
    digitalWrite(io_in13,HIGH);
    manualOff3     = "off";
    buttonStatus13 = "off";
  }else if (StrContains(HTTP_req, "button23=1")){
    digitalWrite(io_in23,LOW);
    manualOff3     = "off";
    buttonStatus23 = "on";
  }else if (StrContains(HTTP_req, "button23=0")){
    digitalWrite(io_in23,HIGH);
    manualOff3     = "off";
    buttonStatus23 = "off";
  }else if (StrContains(HTTP_req, "button33=1")){
    digitalWrite(io_in33,LOW);
    manualOff3     = "off";
    buttonStatus33 = "on";
  }else if (StrContains(HTTP_req, "button33=0")){
    digitalWrite(io_in33,HIGH);
    manualOff3     = "off";
    buttonStatus33 = "off";
  }else if (StrContains(HTTP_req, "dayNight3=1")){
    digitalWrite(io_day_night3,HIGH);
    dayNightStatus3 = "on";
  }else if (StrContains(HTTP_req, "dayNight3=0")){
    digitalWrite(io_day_night3,LOW);
    dayNightStatus3 = "off";
  }
}

// send the XML file DATA status
void XML_response(EthernetClient cl)
{
  Serial.println("");
  Serial.println("**************");
  Serial.print("manualOff1 ");
 Serial.println ( manualOff1);
  Serial.print("powerStatus ");
 Serial.println( powerStatus1);
  Serial.print("buttonStatus11 ");
 Serial.println( buttonStatus11);
  Serial.print("buttonStatus21 ");
 Serial.println( buttonStatus21);
  Serial.print("buttonStatus31 ");
 Serial.println( buttonStatus31);
  Serial.println("**************");
  Serial.println("");
  
    cl.println("<?xml version = \"1.0\" ?>");
    cl.println("<outputs>");

    cl.print("<manualOff>");
      cl.print(manualOff1);
    cl.println("</manualOff>");
    cl.print("<manualOff>");
      cl.print(manualOff2);
    cl.println("</manualOff>");
    cl.print("<manualOff>");
      cl.print(manualOff3);
    cl.println("</manualOff>");
cl.println(" ");
    cl.print("<powerStatus>");
      cl.print(powerStatus1);
    cl.println("</powerStatus>");
    cl.print("<powerStatus>");
      cl.print(powerStatus2);
    cl.println("</powerStatus>");
    cl.print("<powerStatus>");
      cl.print(powerStatus3);
    cl.println("</powerStatus>");
cl.println(" ");
    cl.print("<buttonStatus11>");
      cl.print(buttonStatus11);
    cl.println("</buttonStatus11>");
    cl.print("<buttonStatus21>");
      cl.print(buttonStatus21);
    cl.println("</buttonStatus21>");
    cl.print("<buttonStatus31>");
      cl.print(buttonStatus31);
    cl.println("</buttonStatus31>");
cl.println(" ");
    cl.print("<buttonStatus12>");
      cl.print(buttonStatus12);
    cl.println("</buttonStatus12>");
    cl.print("<buttonStatus22>");
      cl.print(buttonStatus22);
    cl.println("</buttonStatus22>");
    cl.print("<buttonStatus32>");
      cl.print(buttonStatus32);
    cl.println("</buttonStatus32>");
cl.println(" ");
    cl.print("<buttonStatus13>");
      cl.print(buttonStatus13);
    cl.println("</buttonStatus13>");
    cl.print("<buttonStatus23>");
      cl.print(buttonStatus23);
    cl.println("</buttonStatus23>");
    cl.print("<buttonStatus33>");
      cl.print(buttonStatus33);
    cl.println("</buttonStatus33>");
cl.println(" ");
    cl.print("<dayNightStatus>");
      cl.print(dayNightStatus1);
    cl.println("</dayNightStatus>");
    cl.print("<dayNightStatus>");
      cl.print(dayNightStatus2);
    cl.println("</dayNightStatus>");
    cl.print("<dayNightStatus>");
      cl.print(dayNightStatus3);
    cl.println("</dayNightStatus>");
    
    cl.println("</outputs>");
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}

