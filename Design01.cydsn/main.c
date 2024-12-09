#include "project.h"
#include "math.h"
#include <stdio.h>
#include <string.h>

int previous_compare = 0;
int flag = 0;

// Link Lengths
float a2 = 6.2;
float a4 = 3.5;

typedef enum {
    pwm_1 = 1,
    pwm_2 = 2,
} PWM_type;

int BaseMotor_Theta(float Angle) {
    int compare;
    int min_comp = 1400; 
    int max_comp = 7200; 
    int min_angle = 0; 
    int max_angle = 180;
    
    compare = ((max_comp - min_comp) / (max_angle - min_angle)) * (Angle - min_angle) + min_comp;
    return compare;
}

int TopMotor_Theta(float Angle) {
    int compare;
    int min_comp = 1400; 
    int max_comp = 7100; 
    int min_angle = -90; 
    int max_angle = 90;
    
    compare = ((max_comp - min_comp) / (max_angle - min_angle)) * (Angle - min_angle) + min_comp;
    return compare;
}

void MoveMotor(int compare, PWM_type pwm) {
    if (compare - previous_compare > 0) {
        for (int i = previous_compare; i <= compare; i += 20) {
            if (pwm == pwm_1) {
                PWM_WriteCompare1(i);
            } else {
                PWM_WriteCompare2(i);
            }
            CyDelay(4);
        }
    } else if (compare - previous_compare < 0) {
        for (int i = previous_compare; i >= compare; i -= 20) {
            if (pwm == pwm_1) {
                PWM_WriteCompare1(i);
            } else {
                PWM_WriteCompare2(i);
            }
            CyDelay(4);  
        }
    }
    previous_compare = compare;
    CyDelay(1000);
}

int main(void) {

    PWM_Start();
    CyGlobalIntEnable;
    uint8_t ReceiveD1 = UART_1_GetChar();
    while (ReceiveD1 == 0){
        if(ReceiveD1 != 0){
            ReceiveD1 = UART_1_GetChar();
            break;
        }
    }

    CyDelay(1000);
    int ReceiveD2;
    
    LCD_Char_1_ClearDisplay();
            
    while (ReceiveD2 == 0){
        if (ReceiveD2 != 0){
            ReceiveD2 = UART_1_GetChar();
            break;
        }
                    
    }
    
    CyDelay(2000);
    float ReceiveD1D = ReceiveD1 * 1.0;
    float DecReceived = ReceiveD2 / 100.00;
    float Theta1 = ReceiveD1D + DecReceived;
        
    char8 str[8];
    sprintf(str, "%.2f", Theta1);
        
    LCD_Char_1_ClearDisplay();
    CyDelay(20);
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString("Recieved Theta1");
            
    LCD_Char_1_ClearDisplay();
    LCD_Char_1_Position(0, 0);
    LCD_Char_1_PrintString("Waiting");
    int ReceiveD12;
    ReceiveD12 = UART_1_GetChar();
    while (ReceiveD12 == 0){
        if(ReceiveD12 != 0){
            ReceiveD12 = UART_1_GetChar();
            break;
        }        
    }

    CyDelay(1000);
    int ReceiveD22;

    ReceiveD22 = UART_1_GetChar();

    while (ReceiveD22 == 0){
        if (ReceiveD22 != 0){
            ReceiveD22 = UART_1_GetChar();
            break;
        }
    }
    
    CyDelay(2000);
    float ReceiveD1D22 = ReceiveD12 * 1.0;
    float DecReceived22 = ReceiveD22 / 100.00;
    float Received2 = ReceiveD1D22 + DecReceived22;
        
    sprintf(str, "%.2f", Received2);
        
    LCD_Char_1_ClearDisplay();
    CyDelay(20);
    LCD_Char_1_Position(0,0);
    LCD_Char_1_PrintString("Recieved Theta2");
             
    float Theta2 = Received2 - 100;
            
    MoveMotor(BaseMotor_Theta(Theta1),pwm_1);
    MoveMotor(TopMotor_Theta(Theta2),pwm_2);

}

