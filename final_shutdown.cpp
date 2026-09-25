#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    using namespace std;

    while(true) {
        cout << "=========================================" << '\n';
        cout << "Selent an option below :" << '\n';
        cout << "1. Set shutdown timer" << "\n";
        cout << "2. Cancel active shutdown timer" << '\n';
        cout << "3. Exit" << '\n';
        cout << "=========================================" << '\n';

        int choise;

        cin >> choise;

        switch (choise) {
            case 1 : {
                int time = 0;

                while (true){
                    cout << "=========================================" << '\n';
                    cout << "Enter the time to turn off - " << '\n';
                    cout << "=========================================" << '\n';

                    cin >> time;

                    if (cin.fail() || time <= 0) {
                        cin.clear();
                        cin.ignore(32767, '\n');
                        cout << "=========================================" << '\n';
                        cout << "Make sure You have entered value above zero" << '\n';
                        cout << "=========================================" << '\n';
                        continue;
                    }

                    else {
                        int flag = 0;

                        while(true) {
                            cout << "=========================================" << '\n';
                            cout << "You gonna make "<< time << " minutes shutdown timer, continue? [yes/no]" << '\n';
                            cout << "=========================================" << '\n';
                            string answer;

                            cin >> answer;

                            if (cin.fail() || (answer != "no" && answer != "yes")) {
                                cin.clear();
                                cin.ignore(32767, '\n');
                                cout << "=========================================" << '\n';
                                cout << "Make sure You have entered yes/no" << '\n';
                                cout << "=========================================" << '\n';
                                continue;
                            }
                                
                            if (answer == "no"){
                                flag = 1;
                                break;
                            }

                            if (answer == "yes"){
                                flag = 0;
                                break;
                            }
                        }

                        if (flag == 1) {
                            break;
                        }

                        if (flag != 1) {
                                
                            string command = "sudo shutdown -h +" + to_string(time);

                            cout << "=========================================" << '\n';
                            cout << "Executing shutdown command..." << '\n';
                            cout << "=========================================" << '\n';

                            int result = system(command.c_str());

                            if (result == 0){
                                cout << "=========================================" << '\n';
                                cout << "Timer suceesfuly set!" << '\n';
                                cout << "=========================================" << '\n';
                            }

                            else {
                                cout << "=========================================" << '\n';
                                cout << "Failed to set timer. Make sure You have runned the app with admin rights" << '\n';
                                cout << "=========================================" << '\n';
                            }   
                            break;

                            }
                        }
                    }
            break;
            }
        
            case 2: {
                cout << "=========================================" << '\n';
                cout << "Cancelling shutdown timer..." << '\n';
                cout << "=========================================" << '\n';

                if (system("sudo killall shutdown") == 0) {
                    cout << "=========================================" << '\n';
                    cout << "Timer succesfuly cancelled" << '\n';
                    cout << "=========================================" << '\n';
                }

                else {
                    cout << "=========================================" << '\n';
                    cout << "No active shutdown timer found or there is problem with rights" << '\n';
                    cout << "=========================================" << '\n';
                }  
                break;
            }

            case 3: {
                cout << "=========================================" << '\n';
                cout << "Stopping program." << '\n';
                cout << "=========================================" << '\n';
                return 0;
            }

            default: {
                break;
            }
        }
    }
} 