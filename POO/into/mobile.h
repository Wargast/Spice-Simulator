#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__


class mobile{
	public :
		float calcul_position(float);

		void set_vit(float);
		float get_vit() const;

		void set_pos(float);
		float get_pos() const;

		mobile(float,int);
		mobile(float);


	private :
		int m_immatriculation;
	protected:
		float m_vitesse;
		float m_position;
};

class voiture:public mobile{
	private :
		float m_masse, m_consommation;


	public :
		voiture(float, float, float);

		float get_conso() const;
		void set_conso(float);

		float get_masse() const;
		void set_masse(float);
};

class deux_roues:public mobile{
	private :
	int m_type; // 1- essence  2-électrique
	float m_price;

	public :
	deux_roues(float, int, float);

	float get_price() const;
	void set_price(float);

	int get_type() const;
	void set_type(int);

};


#endif
