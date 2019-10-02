class Duree {
private:
  int m_heure, m_min, m_sec;
  void operator+=(Duree const& b);
  friend Duree operator+(Duree const& a, Duree const& b);
  friend bool operator==(Duree const& a, Duree const& b);
  friend bool operator!=(Duree const& a, Duree const& b);
  friend bool operator<(Duree const& a, Duree const& b);
  friend bool operator<=(Duree const& a, Duree const& b);
  friend bool operator>(Duree const& a, Duree const& b);
  friend bool operator>=(Duree const& a, Duree const& b);


public:
  Duree (int heure = 0, int min = 0, int sec = 0);
  virtual ~Duree ();
  void affiche() const;
};
