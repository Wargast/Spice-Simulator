#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__


class mobile{
	public :
		float calcul_position(float);
		
		void set_vit(float);
		float get_vit();

		void set_pos(float);		
		float get_pos();
		
		mobile(float,int);
		

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

		float get_conso();
		void set_conso(float);

		float get_masse();
		void set_masse(float);
};



#endif 
