
class vehicule {
protected :
  int m_prix;

public:
  vehicule (int prix);
  virtual ~vehicule ();
  virtual void affiche() const;
  virtual int nbrRoues() const = 0;
};

class Voiture : public vehicule
{
private:
  int m_portes;


public:
  Voiture (int prix, int portes);
  virtual ~Voiture ();
  virtual void affiche() const;
  virtual int nbrRoues() const;

};

class Moto: public vehicule {
private:
  double m_vitesse;

public:
  Moto (int prix, double vitesseMax);
  virtual ~Moto ();
  virtual void affiche() const;
  virtual int nbrRoues() const;
};


class Camion : public vehicule {
private:
  int m_poids;

public:
  Camion (int prix, int poids);
  virtual ~Camion ();
  virtual void affiche() const;
  virtual int nbrRoues() const;

};
