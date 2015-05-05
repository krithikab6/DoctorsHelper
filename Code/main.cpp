/* Variables for XBee */
#include "xbee.h"
xbee xbee(p13,p14,p15);
char xbeeCommand[202];// = {'3'};
BusOut leds(LED1,LED2,LED3,LED4);

/* Variables for Djikstra */
#include "Djikstra.h"
std::vector<weight_t> min_distance;
std::vector<vertex_t> previous;
adjacency_list_t adjacency_list(16);
std::list<direction_t> pathDirection;
Djikstra d;

/* Variables for the motor */
#include "BotMotor.h"
BotMotor motors(p5,p6,p22,p7,p8,p24);


int main(){
    //0
    adjacency_list[0].push_back(neighbor(1, 1, "S"));//
    
    //1
    adjacency_list[1].push_back(neighbor(0, 1, "B"));//
    adjacency_list[1].push_back(neighbor(5, 1, "R"));//
    
    //2
    adjacency_list[2].push_back(neighbor(6, 1, "U"));
    
    //3
    adjacency_list[3].push_back(neighbor(7, 1, "U"));
    
    //4
    adjacency_list[4].push_back(neighbor(5, 1, "L"));
    adjacency_list[4].push_back(neighbor(8, 1, "L"));//
    
    //5
    adjacency_list[5].push_back(neighbor(1, 1, "D"));
    adjacency_list[5].push_back(neighbor(4, 1, "R"));//
    adjacency_list[5].push_back(neighbor(6, 1, "L"));//
    
    //6
    adjacency_list[6].push_back(neighbor(2, 1, "L"));//
    adjacency_list[6].push_back(neighbor(5, 1, "R"));
    adjacency_list[6].push_back(neighbor(7, 1, "S"));//
    adjacency_list[6].push_back(neighbor(10, 1, "R"));//
    
    //7
    adjacency_list[7].push_back(neighbor(3, 1, "L"));//
    adjacency_list[7].push_back(neighbor(6, 1, "R"));
    
    //8
    adjacency_list[8].push_back(neighbor(4, 1, "D"));
    adjacency_list[8].push_back(neighbor(9, 1, "L"));//
    adjacency_list[8].push_back(neighbor(12, 1, "S"));//
    
    //9
    adjacency_list[9].push_back(neighbor(8, 1, "R"));
    adjacency_list[9].push_back(neighbor(10, 1, "S"));//
    adjacency_list[9].push_back(neighbor(13, 1, "R"));//
    
    //10
    adjacency_list[10].push_back(neighbor(6, 1, "D"));
    adjacency_list[10].push_back(neighbor(9, 1, "R"));
    adjacency_list[10].push_back(neighbor(11, 1, "L"));//
    
    //11
    adjacency_list[11].push_back(neighbor(10, 1, "R"));
    adjacency_list[11].push_back(neighbor(15, 1, "R"));//
    
    //12
    adjacency_list[12].push_back(neighbor(8, 1, "D"));
    
    //13
    adjacency_list[13].push_back(neighbor(9, 1, "D"));
    adjacency_list[13].push_back(neighbor(14, 1, "L"));//
    
    //14
    adjacency_list[14].push_back(neighbor(13, 1, "R"));
    
    //15
    adjacency_list[15].push_back(neighbor(11, 1, "D"));
//    motors.moveForward(0.5);
//    wait(1);
//    motors.stopBot();
    while(1){
        xbee.RecieveData(xbeeCommand,1);
        if(xbeeCommand[0] != '1' && xbeeCommand[0] != '2' && xbeeCommand[0] != '3'){
            printf("Command received - %s, continuing\n\r",xbeeCommand);
            continue;
        }
        else{
            printf("Command received - %s\n\r",xbeeCommand);
            int destination = (xbeeCommand[0] - '0');
            leds = 0x01<<destination;
            destination+=11;
            d.DijkstraComputePaths(0, adjacency_list, min_distance, previous);
            std::list<vertex_t> path = d.DijkstraGetShortestPathTo(destination, previous);
            for (std::list<int>::iterator itP = path.begin(); itP!= path.end()  ; itP++) {
                printf("%d\t",*itP);
                std::list<int>::iterator dupeItP = itP;
                ++dupeItP;
                if (*itP == destination) {
                    break;
                }
                const std::vector<neighbor> &neighbors = adjacency_list[*itP];
                for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
                     neighbor_iter != neighbors.end();
                     neighbor_iter++)
                {
                    if (*(dupeItP) ==  neighbor_iter->target) {
                        printf("%s\t",neighbor_iter->direction);
                        if(neighbor_iter->direction == "S"){
                            pathDirection.push_front(neighbor_iter->direction);
                            motors.moveForward(0.5);
                            wait(1);
                            motors.stopBot();
                            wait(3);
                        }
                        if(neighbor_iter->direction == "R"){
                            pathDirection.push_front("L");
                            motors.turnRight(0.5);
                            wait(1);
                            motors.stopBot();
                            wait(3);
                        }
                        if(neighbor_iter->direction == "L"){
                            pathDirection.push_front("R");
                            motors.turnLeft(0.5);
                            wait(1);
                            motors.stopBot();
                            wait(3);
                        }
                    }
                    //            std::cout << "Direction " << dir << std::endl;
                    
                }
                printf("\n\r");
                
            }
            motors.stopBot();
            wait(5);
            motors.turnAround(0.5);
//            wait(1.2);
            pathDirection.push_front("S");
            for(std::list<std::string>::iterator it = pathDirection.begin(); it!=pathDirection.end(); it++){
//                printf("%s\t",it->c_str());
                if(*it == "S"){
                    printf("A - %s\t",it->c_str());
                    motors.moveForward(0.5);
                    wait(1);
                    motors.stopBot();
                    wait(3);
                }
                if(*it == "R"){
                    printf("B - %s\t",it->c_str());
                    motors.turnRight(0.5);
                    wait(1);
                    motors.stopBot();
                    wait(3);
                }
                if(*it == "L"){
                    printf("C - %s\t",it->c_str());
                    motors.turnLeft(0.5);
                    wait(1);
                    motors.stopBot();
                    wait(3);
                }
            }
            printf("\n\r");
            motors.stopBot();
            pathDirection.clear();
            continue;
        }

    }

    printf("Out of while");
   

}