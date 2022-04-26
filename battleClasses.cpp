#include <string>

using namespace std;

class studentHP {
  string stuName;
  string stuHouse;
  string station;

  public:
  studentHP(string newStuName, string newStuHouse, string newStation); //constructor

  void reAssign(string setNewStation); //re-assign
//"Get" functions:
  string getStuName();
  string getStuHouse();
  string getStation();
};

class battleSim {
  string simObjName;
  int objHealth;
  string lifeStatus;
  int shieldAmount; //if attack shield add shield to health set shield to zero then take damage
  bool disabled;

  public:
  battleSim(string setObjName, string newStatus, int newObjHealth);

  ~battleSim();
  //SET
  void setObjHealth(int setHealth);

  void setStatus(string setNewStatus);

  void addHealth(int addMoreHealth);

  void subtractHealth(int subtrHealth);

  void disable(bool able);

  void addShield(int shieldHP);//added before made shield var still works
  
  void setShield(int setNewShield);
  //GET
  int getHealth();

  string getStatus();

  string getObjName();

  bool getDisabled();

  int getShields();
};
//ana, dev, gem, hal, lee, vir, jack, jup, nel, fra, dru, rob, coop, kiya, elo, lin, tia, mead, kay, est, rhys, brig
class name {
  public:
  static const int ana = 0;
  static const int dev = 1;
  static const int gem = 2;
  static const int hal = 3;
  static const int lee = 4;
  static const int vir = 5;
  static const int jack = 6;
  static const int jup = 7;
  static const int nel = 8;
  static const int fra = 9;
  static const int dru = 10;
  static const int rob = 11;
  static const int coop = 12;
  static const int kiya = 13;
  static const int elo = 14;
  static const int lin = 15;
  static const int tia = 16;
  static const int mead = 17;
  static const int kay = 18;
  static const int est = 19;
  static const int rhys = 20;
  static const int brig = 21;
};
