//
// Created by jglrxavpok on 17/10/19.
//
#include <XL430.h>
#include "changementID.h"

/**
 * Change l'ID de TOUS les XL connectés à la valeur dans la variable 'id'
 */
void changeID(DynamixelManager* manager) {
    int id = 1;
    XL430* broadcast = new XL430(static_cast<uint8_t>(dynamixelV2::broadcastId), *manager);
    broadcast->changeID(id);
}