#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
////////////////////////             test1              ////////////////////////
////////////////////////////////////////////////////////////////////////////////

void f(); // declaration
void f() { /* code*/ } // definition

class mouse
{
public:
    mouse(int x, int y); // declaration constructeur

    void move(int x, int y); // declaration fonction membre

    int x_; // variable membre
    int y_;
};

// definition constructeur (la classe mouse crée un scope "mouse" la fonction mouse() (constructeur) est dans le scope mouse)
mouse::mouse(int x, int y) : x_{ x }, y_{ y } // initialisation des membres x_ et y_ avec les parametres
{

}

void mouse::move(int x, int y) // definition fonction membre de mouse
{
    x_ = x;
    y_ = y;
}

void test1()
{
    mouse m{0, 0};
    std::cout << m.x_ << ":" << m.y_ << std::endl;

    m.move(4, 5);
    std::cout << m.x_ << ":" << m.y_ << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////             test2              ////////////////////////
////////////////////////////////////////////////////////////////////////////////
// access specifier
class zeta2
{
public:
  int pub;

  void pub_func() {}

private:
  int priv;

  void priv_func() {}
};


void test2()
{
  zeta2 z;
  z.pub = 3;
  z.pub_func();

  // z.priv = 3; // compilation error
  // z.priv_func(); // compilation error
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////             test3              ////////////////////////
////////////////////////////////////////////////////////////////////////////////
// héritage

class player
{
public:
  player(std::string name)
    : name_{ name } // name_{ std::move(name) },  à voir plus tard
  {

  }

  virtual int skill() // virtual autorise les classes dérivées à remplacer cette fonction
  {
    return 0;
  }

  const std::string& name() const
  {
    return name_;
  }

private:
    std::string name_;
};

class setsunaf : public player // setsunaf hérite de player, player est la classe de base de setsunaf, setsunaf est la class dérivée de player
{
public:
  setsunaf() : player("setsunaf") {} // on appelle le constructeur de la classe de base

  int skill() override // on remplace la fonction de la classe de base
  {
    return 5;
  }
};

class groku : public player
{
public:
  groku() : player("groku") {} // on appelle le constructeur de la classe de base

  int skill() override // on remplace la fonction de la classe de base
  {
    return 9000;
  }

  void special_ultimate_combo_of_the_doom()
  {
    std::cout << "\nBOOOOOOOOOOOOOOOOM\n";
  }
};


void test3()
{
  player p{ "player"};
  std::cout << "player name : " << p.name() << " | skill : " << p.skill() << std::endl;

  setsunaf s;
  std::cout << "player name : " << s.name() << " | skill : " << s.skill() << std::endl;

  groku g;
  std::cout << "player name : " << g.name() << " | skill : " << g.skill() << std::endl;

  groku* groku_pointer = &g;
  std::cout << "\ngroku_pointer " << groku_pointer->skill();
  groku_pointer->special_ultimate_combo_of_the_doom();

  // polymorphisme
  player* player_pointer = &g; // g est det ype groku mais hérite de player, on peut créer un pointeur de type de base (player) qui pointe sur un objet de type dérivé (groku)
  std::cout << "\nplayer_pointer " << player_pointer->skill();
  // &g est un pointeur sur le type groku
  // player_pointer est un pointeur sur le type player qui pointe sur un objet de type groku
  // player_pointer->skill() appelle la fonction skill() de groku grace au polymorphisme (fonction virtuelle)
  // pour toute fonction virtuelle, le type de l'objet sera utilisé

  // player_pointer->special_ultimate_combo_of_the_doom(); // le type player n'a pas la fonction membre special_ultimate_combo_of_the_doom
}


int main()
{
  test1();
  test2();
  test3();

    return 0;
}