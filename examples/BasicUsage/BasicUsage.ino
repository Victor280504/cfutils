#include <Button.h>
#include <Event.h>
#include <EventHandler.h>
#include <Led.h>
#include <Logger.h>
#include <PushButton.h>
#include <SliderButton.h>

PushButton myButton(2);
Logger logger;

void onButtonPress() {
    logger.log(INFO, "Botão pressionado!");
}

void setup() {
    Logger::begin(9600);
    myButton.setEventCallback(onButtonPress);
}

void loop() {
    myButton.update();
}