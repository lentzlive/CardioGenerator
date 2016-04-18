/*
 Name:    cardioGenerator.ino
 Created: 4/18/2016 5:55:18 PM
 Author:  Davide
*/


#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

const PROGMEM uint16_t DACLookup_Cardio_9Bit[543] =
{
  751, 752, 753, 754, 755, 756, 757, 758, 761, 765,
  770, 774, 778, 782, 786, 791, 795, 800, 804, 812,
  819, 827, 834, 842, 850, 860, 870, 880, 890, 897,
  901, 905, 909, 913, 917, 921, 925, 931, 938, 943,
  950, 955, 962, 967, 973, 978, 983, 988, 993, 998,
  1003, 1008, 1011, 1014, 1017, 1020, 1023, 1026, 1030, 1029,
  1027, 1025, 1023, 1021, 1019, 1017, 1014, 1013, 1010, 1009,
  1006, 1005, 1002, 1001, 997, 994, 990, 986, 982, 978,
  974, 972, 969, 966, 962, 959, 956, 953, 947, 942,
  937, 932, 927, 922, 917, 913, 909, 904, 900, 896,
  892, 888, 882, 877, 870, 864, 858, 852, 846, 839,
  832, 824, 817, 810, 803, 796, 790, 786, 782, 779,
  776, 773, 770, 767, 764, 762, 759, 756, 754, 751,
  750, 751, 752, 753, 754, 755, 756, 757, 757, 757,
  757, 757, 757, 757, 757, 758, 760, 762, 763, 765,
  766, 768, 770, 771, 772, 772, 772, 772, 772, 772,
  770, 768, 766, 763, 761, 758, 755, 753, 750, 746,
  741, 736, 730, 726, 721, 715, 708, 692, 656, 586,
  485, 444, 406, 506, 558, 602, 646, 717, 782, 818,
  855, 902, 990, 1078, 1166, 1668, 1797, 1979, 2039,
  2076, 2113, 2156, 2466, 2508, 2550, 2574, 2652, 2722, 2794,
  2865, 3043, 3078, 3112, 3038, 2754, 2762, 2638, 2442, 2255,
  2248, 1780, 1806, 1514, 1387, 1300, 798, 722, 284, 301,
  162, 24, 26, 49, 72, 95, 128, 190, 220, 234,
  247, 260, 274, 297, 319, 343, 387, 434, 482, 522,
  562, 606, 642, 670, 685, 700, 716, 734, 750, 774,
  813, 828, 833, 838, 843, 848, 853, 853, 851, 849,
  846, 845, 842, 841, 838, 837, 834, 833, 830, 828,
  826, 824, 822, 820, 818, 815, 814, 811, 809, 806,
  805, 802, 801, 799, 798, 797, 795, 794, 793, 792,
  790, 789, 788, 786, 785, 782, 781, 778, 777, 774,
  773, 770, 770, 770, 770, 770, 770, 770, 770, 770,
  770, 770, 770, 770, 770, 770, 770, 770, 770, 770,
  770, 771, 772, 773, 774, 774, 775, 776, 777, 778,
  779, 781, 782, 784, 786, 788, 790, 791, 793, 794,
  796, 798, 799, 802, 805, 809, 812, 815, 818, 822,
  826, 829, 832, 836, 840, 844, 847, 851, 855, 861,
  866, 870, 876, 881, 886, 891, 896, 901, 906, 913,
  919, 926, 933, 938, 942, 946, 950, 954, 958, 962,
  966, 971, 977, 982, 986, 992, 997, 1000, 1003, 1007,
  1010, 1015, 1022, 1029, 1035, 1042, 1047, 1052, 1058, 1062,
  1067, 1073, 1074, 1076, 1078, 1079, 1081, 1082, 1084, 1086,
  1087, 1087, 1087, 1087, 1087, 1086, 1085, 1083, 1082, 1080,
  1078, 1076, 1074, 1073, 1071, 1069, 1067, 1066, 1063, 1062,
  1059, 1058, 1056, 1054, 1052, 1050, 1046, 1041, 1035, 1030,
  1025, 1020, 1016, 1012, 1008, 1005, 1001,997, 992, 986,
  982, 977, 971, 966, 961, 955, 949, 942, 936, 930,
  923, 918, 915, 912, 909, 905, 902, 898, 894, 891,
  886, 879, 872, 866, 859, 855, 851, 846, 842, 838,
  834, 830, 827, 823, 820, 817, 814, 810, 807, 804,
  801, 798, 795, 792, 793, 794, 795, 797, 798, 799,
  798, 798, 797, 796, 795, 794, 793, 792, 791, 791,
  791, 791, 791, 791, 791, 790, 789, 787, 786, 785,
  784, 786, 787, 789, 790, 792, 794, 796, 798, 799,
  802, 804,806, 810
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");

  // For Adafruit MCP4725A1 the address is 0x62 (default) or 0x63 (ADDR pin tied to VCC)
  // For MCP4725A0 the address is 0x60 or 0x61
  // For MCP4725A2 the address is 0x64 or 0x65
  dac.begin(0x62);

  Serial.println("Generating a Cardio wave");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t i;

  for (i = 0; i < 543; i++)
  {
    dac.setVoltage(pgm_read_word(&(DACLookup_Cardio_9Bit[i])), false);
    delay(2); // Ritardo di 2 ms 
  }
}
