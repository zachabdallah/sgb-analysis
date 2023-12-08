//
//  main.cpp
//  sgb-analysis
//
//  Created by Zach Abdallah on 1/16/23.
//

#include <iostream>
using namespace std;

int main() {
    cout << "How big is your target? (type 1-5 for 1x1 to 5x5): ";
    double t92_damage = 3300.0;
    double t80_damage = 3527.1; //you would only ever use t80 with upgraded hexbow
    
    int target_size;
    double arrow_amount;
    double arrow_damage[5] = {140.0, 160.0, 146.5, 133.0, 120.0};
    cin >> target_size;
    cout << endl;
    switch(target_size){
        case 1:{
            cout << "   1x1 size" << endl;
            arrow_amount = 1.16;
            break;
        }
        case 2:{
            cout << "   2x2 size" << endl;
            arrow_amount = 1.64;
            break;
        }
        case 3:{
            cout << "   3x3 size" << endl;
            arrow_amount = 2.44;
            break;
        }
        case 4:{
            cout << "   4x4 size" << endl;
            arrow_amount = 2.64;
            break;
        }
        case 5:{
            cout << "   5x5 size" << endl;
            arrow_amount = 3.31;
            break;
        }
    }
    cout << "this guide assumes the use of smoke cloud on the target" << endl;
    cout << "it also assumes 3300 ability damage for t92 and 3527 for upgraded hexhunter bow, which takes into account elder overloads, t99 prayer, and t90+ high level dps gear. It also assumes the target to be under vulnerability" << endl << endl;
    
    double original_damage_average = 0.0;
    for (int i = 0; i < (int)arrow_amount + 1; ++i){
        if (i == (int)arrow_amount){
            original_damage_average += arrow_damage[i] * (arrow_amount - (int)arrow_amount);
            break;
        }
        original_damage_average += arrow_damage[i];
    }
    cout << "average damage with "<< arrow_amount << " arrows : " << original_damage_average << "%" << endl;
    
    double percentage_increase = 0.0;
    cout << original_damage_average;
    percentage_increase = (0.084 * ((15720/t92_damage)*100 * arrow_amount)) / original_damage_average;
    double ruby_average_damage_percentage = 0.084 * (15720/t92_damage * arrow_amount) * 100 + original_damage_average;
    //think about it like this :: 8% of the time youre doing say 40,000 damage(1333%), and the other 92% of the time you do just the base amount of damage. That means the average increase to your damage is (.08 * 40,000) +base damage
    cout << "% becomes " << ruby_average_damage_percentage << "% with ruby bolts on average: an increase of " << percentage_increase * 100 << "%" << endl;
    cout << "in other words, " << (int)(original_damage_average/100*t92_damage) << " dmg becomes " << (int)(ruby_average_damage_percentage/100*t92_damage) << " damage" << endl << endl;
    
    
    double ruby_average_damage_percentage_without_grimoire = 0.084 * (12576/t92_damage * arrow_amount) * 100 + original_damage_average;
    percentage_increase = (0.084 * ((12576/t92_damage)*100 * arrow_amount)) / original_damage_average;
    
    cout << "if you don't have grimoire though, the percentage increase is only " << percentage_increase * 100 << "%" << endl << endl;
    
    
    
    cout << original_damage_average;
    percentage_increase = ((((0.144 * 0.25) + 1) * original_damage_average) / original_damage_average) - 1;
    double onyx_average_damage_percentage = original_damage_average * ((0.144 * 0.25) + 1); //14.4% chance of dealing 25 % damage
    cout << "% becomes " << onyx_average_damage_percentage << "% with onyx bolts on average: an increase of " << percentage_increase * 100 << "%" << endl;
    cout << "in other words, " << (int)(original_damage_average/100*t92_damage) << " dmg becomes " << (int)(onyx_average_damage_percentage/100*t92_damage) << " damage" << endl;
    
    cout << endl << "      if cast outside of death swiftness: ";
    cout << endl << "if using an upgraded hexhunter bow with ful arrows, final dmg is " << (int)(original_damage_average/100*t80_damage * 1.15) << endl;
    
    if ((ruby_average_damage_percentage/100*t92_damage) >= ((int)(original_damage_average/100*t80_damage * 1.15))){
        cout << "ruby spec is better on average than hexhunter+ful arrow spec by " << (((ruby_average_damage_percentage/100*t92_damage)/((int)(original_damage_average/100*t80_damage * 1.15)))-1)*100 << "%" << endl;
        cout << "without grimoire, hex+ful is stronger by " << original_damage_average/100*t80_damage * 1.15 / (ruby_average_damage_percentage_without_grimoire/100*t92_damage) << "%" << endl << endl;
    }
    
    cout << "if the spec were not to proc, though, then hexbow+ful is better by " <<
    ((original_damage_average/100*t80_damage * 1.15)/(original_damage_average/100 *t92_damage)-1)*100 << "%"<< endl << endl;
    
    cout << "if cast within a deaths swiftness using hex+ful, the sgb spec is ";
    cout << (original_damage_average/100*t80_damage * 1.15 * 1.5) / (ruby_average_damage_percentage/100*t92_damage * 1.5) << "%";
    cout << " stronger than the average weighted damage of it being cast with ruby bolts." << endl;
    cout << "that means that the average damage of hex+ful in ds is " << ((original_damage_average/100*t80_damage * 1.15) * 1.5);
    cout << " whereas an unprocced ruby bolt spec is " << original_damage_average/100*t92_damage * 1.5;
    cout << " dmg, proccing at " << 15720*arrow_amount << " dmg with grimoire 8.4% of the time given that there are on average ";
    cout << arrow_amount << " arrows that hit during the spec.";
    cout << "if not using a grimoire, hex+ful is better by ";
    cout << (original_damage_average/100*t80_damage * 1.15 * 1.5) / (ruby_average_damage_percentage_without_grimoire/100*t92_damage * 1.5) << "%" << endl;
    
    return 0;
}
