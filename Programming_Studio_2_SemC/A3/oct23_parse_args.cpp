#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(const int argc, const char** argv)
{
    cout << "argc = " << argc << endl;
    cout << "argv = " << argv << endl;

    
    // cars = ["ferrari", "lamborghini", "porsche"]
    // => cars = [
    //     ['f', 'e', 'r' ...],
    //     ['l', 'a'...]
    // ]

    int loc_x, loc_z;
    int village_size = 200;


    for (int i = 0; i < argc; i++) {
        cout << "i = " << argv[i] << endl;

        // argv[i] -> "key=value"
        

        // options: 
        //     --loc
        //     --village-size
        //     --plot-border
        //     --seed
        //     --testmode

        // if key == "--loc":
        //     value = "1,2"
        //     => x = 1, z = 2
        
        // else if key == "--village-size":
        //     value = "3"
        //     village_size = stoi(value);

        int j = 0;
        string key = "";
        while (argv[i][j] != '=') {
            key += argv[i][j];
            j++;
        }
        
        cout << ">> key: " << key << endl;

        // skipping the equal sign for value
        j++;
        
        string value = "";
        while (j < strlen(argv[i])) {
            value += argv[i][j];
            j++;
        }

        cout << ">> value: " << value << endl;

        if (key == "--village-size") {
            village_size = stoi(value);
        } else if (key == "--loc") {
            string locx = {value[0]};
            string locz = {value[2]};
            loc_x = stoi(locx);
            loc_z = stoi(locz);
        } else {
            cout << key << " is an invalid key" << endl;
        }

    }

    // ./main.out --loc=1,2 --village-size=3
    // ./main.out --village-size=3 --loc=1,2

    cout << "loc_x = " << loc_x << endl;
    cout << "loc_z = " << loc_z << endl;
    cout << "village_size = " << village_size << endl;

    

    return EXIT_SUCCESS;
}
