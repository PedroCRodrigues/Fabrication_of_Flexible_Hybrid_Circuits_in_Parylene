const int LED_red = 3;
const int LED_green = 6;

void setup() {
    pinMode (LED_red, OUTPUT);
    pinMode (LED_green, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite (LED_red, HIGH);
    digitalWrite (LED_green, LOW);
    Serial.println("Entrou");
    delay (1000);
    digitalWrite (LED_red, LOW);
    digitalWrite (LED_green, HIGH);
    Serial.write("Saiu");
    Serial.println("\t");
    delay (1000);
}
