#include <XL430.h>
#include "Arduino.h"
#include "DynamixelManager.h"
#include "changementID.h"

/**
 * Code d'initialisation d'un XL d'ID 1, et un d'ID 2, et leur fait faire des aller-retours.
 *
 * Il est possible de changer l'ID d'un XL avec le code dans 'changementID.cpp' en décommentant la ligne commençant par 'changeID'.
 * ATTENTION: Cela change l'ID de TOUS les moteurs connectés en même temps. (voir le code dans changementID.cpp pour changer l'ID à appliquer)
 *
 * Pour avoir plusieurs moteurs, il suffit de les connecter en série avec le même câble. Dans le code, il faut
 * créer un nouveau moteur (cf ligne avec '// création du moteur dans le code')
 */
float Angle = 10;
void setup() {
    Serial.begin(9600);
    DynamixelManager* manager = new DynamixelManager(D2, D2); // Manageur qui permet de communiquer avec les XL
    DynamixelMotor* motor1 = manager->createMotor(1 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 1
    //DynamixelMotor* motor2 = manager->createMotor(2 /* ID du XL */, XL430GeneratorFunction); // XL avec l'ID 2

    motor1->changeLED(true); // allume la LED du XL 1
    //motor2->changeLED(true); // allume la LED du XL 2

    motor1->toggleTorque(true);
/*bool toto;
/*
    motor1->toggleTorque(false);
    while(true){
        motor1->getCurrentAngle( Angle);
        Serial.println(Angle);
        delay(500);
        motor1->changeLED(toto);
    toto = !toto;}
*/
    while(true) {
        motor1->setGoalAngle(90.0f); // fais aller le moteur 1 à 90°
        // motor2->setGoalAngle(270.0f); // fais aller le moteur 2 à 270°
        delay(500); // 500ms d'attente
        motor1->setGoalAngle(180.0f); // fais aller le moteur 1 à 180° (milieu)
        //motor2->setGoalAngle(180.0f); // fais aller le moteur 2 à 180° (milieu)
        delay(500); // 500ms d'attente
        motor1->setGoalAngle(270.0f); // fais aller le moteur 1 à 270°
        //motor2->setGoalAngle(90.0f); // fais aller le moteur 2 à 90°
        delay(500); // 500ms d'attente
    }
}
void loop(){

}