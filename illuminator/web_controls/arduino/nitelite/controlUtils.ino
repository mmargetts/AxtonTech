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
String xlrPowerStatus     = "off";
String zoomPowerStatus    = "off";
String hybridPowerStatus  = "off";
String strobeState        = "off";
String alarm              = "off";
long previousMillis       = 0;
long interval             = 1; 


int io_jumper_hybrid      = 22;
int io_jumper_zoom        = 26;
int io_jumper_xlr         = 30;

int io_jumper_illuminator1 = 42;
int io_power1             = 45;
int io_day_night1         = 47;
int io_in31               = 49;
int io_in21               = 51;
int io_in11               = 53;

int io_jumper_illuminator2 = 38;
int io_power2             = 33;
int io_day_night2         = 35;
int io_in32               = 37;
int io_in22               = 39;
int io_in12               = 41;


int io_jumper_illuminator3 = 34;
int io_power3             = 23;
int io_day_night3         = 25;
int io_in33               = 27;
int io_in23               = 29;
int io_in13               = 31;



int pinInArrary[] = {io_jumper_illuminator1, io_jumper_illuminator2, io_jumper_illuminator3, io_power1, io_power2, io_power3, io_jumper_hybrid, io_jumper_zoom, io_jumper_xlr};
int pinOutArrary[] = {io_in11, io_in21, io_in31, io_in12, io_in22, io_in32, io_in13, io_in23, io_in33};
int io_in1Arrary[] = {io_in11, io_in21, io_in31};
int io_in2Arrary[] = {io_in12, io_in22, io_in32};
int io_in3Arrary[] = {io_in13, io_in23, io_in33};


void initPins()
{
  
    analogWriteResolution(4);
  pinMode(2,OUTPUT);

  // set default pin modes
  for (int i = 0; i < sizeof(pinInArrary) / sizeof(int); i++) {
    pinMode(pinInArrary[i], INPUT_PULLUP);
  }

  for (int i = 0; i < sizeof(pinOutArrary) / sizeof(int); i++) {
    pinMode(pinOutArrary[i], OUTPUT);
    digitalWrite(pinOutArrary[i], HIGH);
  }
  pinMode(io_day_night1, OUTPUT);
  pinMode(io_day_night2, OUTPUT);
  pinMode(io_day_night3, OUTPUT);
  digitalWrite(io_day_night1, LOW);
  digitalWrite(io_day_night2, LOW);
  digitalWrite(io_day_night3, LOW);


}

void setManualOff(int io[]) {
  for (int i = 0; i < (sizeof(io) / sizeof(int)) - 1; i++) {
    Serial.print("setting io high ");
    Serial.println(io[i]);
    digitalWrite(io[i], HIGH);
  }
}

void xlrOff() {
  buttonStatus11 = "off";
  buttonStatus31 = "off";
  xlrPowerStatus = "off";
  digitalWrite(io_in11, HIGH);
  digitalWrite(io_in21, HIGH);
  digitalWrite(io_in31, HIGH);

}

void xlrLow() {
  buttonStatus11 = "on";
  buttonStatus31 = "off";
  digitalWrite(io_in11, LOW);
  digitalWrite(io_in21, HIGH);
  digitalWrite(io_in31, HIGH);

}

void xlrHigh() {
  buttonStatus11 = "off";
  buttonStatus31 = "on";
  digitalWrite(io_in11, LOW);
  digitalWrite(io_in21, LOW);
  digitalWrite(io_in31, LOW);
}


void zoomOff() {
  buttonStatus12 = "off";
  buttonStatus22 = "off";
  buttonStatus32 = "off";
  zoomPowerStatus = "off";
  digitalWrite(io_in12, HIGH);
  digitalWrite(io_in22, HIGH);
  digitalWrite(io_in32, HIGH);
}

void zoomWide() {
  buttonStatus12 = "on";
  buttonStatus22 = "off";
  buttonStatus32 = "off";
  digitalWrite(io_in12, LOW);
  digitalWrite(io_in22, HIGH);
  digitalWrite(io_in32, HIGH);
}

void zoomMedium() {
  buttonStatus12 = "off";
  buttonStatus22 = "on";
  buttonStatus32 = "off";
  digitalWrite(io_in12, HIGH);
  digitalWrite(io_in22, LOW);
  digitalWrite(io_in32, HIGH);
}

void zoomNarrow() {
  buttonStatus12 = "off";
  buttonStatus22 = "off";
  buttonStatus32 = "on";
  digitalWrite(io_in12, HIGH);
  digitalWrite(io_in22, HIGH);
  digitalWrite(io_in32, LOW);
}

void hybridOff() {
  buttonStatus13 = "off";
  buttonStatus23 = "off";
  buttonStatus33 = "off";
  hybridPowerStatus = "off";
  digitalWrite(io_in13, HIGH);
  digitalWrite(io_in23, HIGH);
  digitalWrite(io_in33, HIGH);
  strobeState = "off";
  alarm="off";
}

void hybridIR() {
  alarm="off";
  strobeState="off";
  buttonStatus13 = "on";
  buttonStatus23 = "off";
  buttonStatus33 = "off";
  digitalWrite(io_in13, LOW);
  digitalWrite(io_in23, HIGH);
  digitalWrite(io_in33, HIGH);
}

void hybridWhiteLight() {
  alarm="off";
  strobeState="off";
  buttonStatus13 = "off";
  buttonStatus23 = "on";
  buttonStatus33 = "off";
  digitalWrite(io_in13, HIGH);
  digitalWrite(io_in23, LOW);
  digitalWrite(io_in33, HIGH);
}

void hybridAlarm() {
  alarm="on";
  strobeState="on";
  buttonStatus13 = "off";
  buttonStatus23 = "off";
  buttonStatus33 = "on";
  digitalWrite(io_in13, HIGH);
  digitalWrite(io_in23, LOW);
  digitalWrite(io_in33, HIGH);
}



// checks if received HTTP request is switching on/off LEDs
// also saves the state of the LEDs
void SetDLs(void)
{
  unsigned long currentMillis = millis();

  Serial.println(HTTP_req);

  // ***************** XLR *****************
  if (StrContains(HTTP_req, "xlrPower=1")) {
    zoomOff();
    hybridOff();
    xlrPowerStatus = "on";
    if (StrContains(HTTP_req, "button11=1")) {       //LOW
      xlrLow();
    } else if (StrContains(HTTP_req, "button31=1")) { // HIGH
      xlrHigh();
    }
  } else  if (StrContains(HTTP_req, "xlrPower=0")) { //turn it off
    xlrOff();
  }
  // ***************** ZOOM *****************
  if (StrContains(HTTP_req, "zoomPower=1")) {
    xlrOff();
    hybridOff();
    zoomPowerStatus = "on";
    if (StrContains(HTTP_req,       "button12=1")) {       //WIDE
      zoomWide();
    } else if (StrContains(HTTP_req, "button22=1")) { // MEDIUM
      zoomMedium();
    } else if (StrContains(HTTP_req, "button32=1")) { // NARROW
      zoomNarrow();
    }
  } else if (StrContains(HTTP_req, "zoomPower=0")) { //turn it off
    zoomOff();
  }
  // ***************** HYBRID *****************
  if (StrContains(HTTP_req, "hybridPower=1")) {
    xlrOff();
    zoomOff();
    hybridPowerStatus = "on";
    if (StrContains(HTTP_req,        "button13=1")) {       //IR
      hybridIR();
    } else if (StrContains(HTTP_req, "button23=1")) { // WHITE LIGHT
      hybridWhiteLight();
    } else if (StrContains(HTTP_req, "button33=1")) { // STROBE
      hybridAlarm();
    }
  }  else if (StrContains(HTTP_req, "hybridPower=0")) { //turn it off
      hybridOff();
    }
    
    if (alarm == "on" && currentMillis - previousMillis > interval ){
      previousMillis = currentMillis;
      if (strobeState == "on"){
        digitalWrite(io_in23, HIGH);
        strobeState = "off";
      }else{
        digitalWrite(io_in23, LOW);
        strobeState = "on";
    }
    }
}




// send the XML file DATA status
void XML_response(EthernetClient cl)
{

  cl.println("<?xml version = \"1.0\" ?>");
  cl.println("<outputs>");

  cl.print("<xlrPower>");
  cl.print(xlrPowerStatus);
  cl.println("</xlrPower>");
  cl.print("<zoomPowerStatus>");
  cl.print(zoomPowerStatus);
  cl.println("</zoomPowerStatus>");
  cl.print("<hybridPowerStatus>");
  cl.print(hybridPowerStatus);
  cl.println("</hybridPowerStatus>");
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

