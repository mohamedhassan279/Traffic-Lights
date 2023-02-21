const int BTN_PIN = 2;
const int RED_LED = 3;
const int GREEN_LED = 5;
int buttonState = HIGH;
int redState = HIGH;
int greenState = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, redState);
  digitalWrite(GREEN_LED, greenState);
}

void loop() {
  // put your main code here, to run repeatedly:
  // the button was pressed
  if(debounce(BTN_PIN) == LOW && buttonState == HIGH){
    buttonState = LOW;        // update the state
    redState = !redState;         // toggle the LED state
    greenState = !greenState;
  }
  //when the button is open after pressing it
  else if(debounce(BTN_PIN) == HIGH && buttonState == LOW){
    buttonState = HIGH;
  }

  Serial.println(buttonState);

  // set the 2 LEDS
  digitalWrite(RED_LED, redState);
  digitalWrite(GREEN_LED, greenState);
}

boolean debounce(int pin)
{
  boolean state;
  boolean previousState;
  previousState = digitalRead(pin);
  for(int i=0; i<10; i++){
    delay(1);  // wait for 1 millisecond
    state = digitalRead(pin);
    if(state != previousState){
      i = 0;  //reset the iterative counter
      previousState = state;  //set the previous state
    }
  }
  return state;
}
