.SILENT:
CLASSES=Classes/
OBJS=Classes/Modele.o
CO=g++ -I Classes/

# Test1:	Test1.cpp Classes/Modele.o
# 	#g++ Test1.cpp Classes/Modele.o -I Classes/ -o Test1
# 	$(CO) $(OBJS) $(Classes/Voiture.o) Test1.cpp -o Test1
# 	echo "creation du fichier Test1a"

# Test2a:	Test2a.cpp Classes/Modele.o Classes/Voiture.o
# 	g++ Test2a.cpp Classes/Modele.o Classes/Voiture.o -I Classes/ -o Test2a
# 	$(CO) $(OBJS) $(Classes/Voiture.o) Test2a.cpp -o Test2a
# 	echo "creation du fichier Test2a"

# Test2b:	Test2b.cpp Classes/Option.o 
# 	g++ Test2b.cpp Classes/Option.o -I Classes/ -o Test2b

# Test2c:	Test2c.cpp Classes/Modele.o Classes/Voiture.o Classes/Option.o
# 	g++ Test2c.cpp Classes/Modele.o Classes/Voiture.o Classes/Option.o -I Classes/ -o Test2c

Test3:	Test3.cpp Classes/Modele.o Classes/Voiture.o Classes/Option.o
	g++ Test3.cpp Classes/Modele.o Classes/Voiture.o Classes/Option.o -I Classes/ -o Test3

# Test4:	Test4.cpp Classes/Personne.o Classes/Intervenant.o Classes/Client.o Classes/Employe.o
# 	g++ Test4.cpp Classes/Personne.o Classes/Intervenant.o Classes/Client.o Classes/Employe.o -I Classes/ -o Test4

Option.o:	Classes/Option.h Classes/Option.cpp
	g++ Classes/Option.cpp -c -o Classes/Option.o

Modele.o:	Classes/Modele.h Classes/Modele.cpp
	#g++ Classes/Modele.cpp -c -o Classes/Modele.o
	$(CO) Classes/Modele.cpp -D DEBUG -c -o Classes/Modele.o
	echo "creation de Modele.o"

Voiture.o:	Classes/Voiture.h Classes/Voiture.cpp
	#g++ Classes/Voiture.cpp -c -o Classes/Voiture.o
	$(CO) Classes/Voiture.cpp -D DEBUG -c -o Classes/Voiture.o
	echo "creation de Voiture.o"

# Personne.o:	Classes/Personne.h Classes/Personne.cpp
# 	g++ Classes/Personne.cpp -c -o Classes/Personne.o

# Intervenant.o:	Classes/Intervenant.h Classes/Intervenant.cpp
# 	g++ Classes/Intervenant.cpp -c -o Classes/Intervenant.o

# Client.o:	Classes/Client.h Classes/Client.cpp
# 	g++ Classes/Client.cpp -c -o Classes/Client.o

# Employe.o:	Classes/Employe.h Classes/Employe.cpp
# 	g++ Classe/Employe.cpp -c -o Classes/Employe.o

clean:
	rm $(CLASSES)*.o
	echo "clean"