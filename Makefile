include config

ifeq ($(LINUX),1)
C++FLAGS = -I. \
           -I/usr/include \
           -I/home/hughperkins/dev/Mesa-6.2.1/include \
           -g -fPIC 
CCFLAGS = $(C++FLAGS)
C++ = g++ $(C++FLAGS) -c
OBJPOSTFIX = o
EXESUFFIX = 

all:	liblaminarchaos.a

install:	
	install liblaminarchaos.a $(LOCALPREFIX)/lib ; \
	install MD2Mesh.h $(LOCALPREFIX)/include
	install MD2MeshInterface.h $(LOCALPREFIX)/include

endif

ifeq ($(MSVC),1)
C++FLAGS = /I.
CCFLAGS = $(C++FLAGS)
C++ = cl $(C++FLAGS) /c 
OBJPOSTFIX = obj
EXESUFFIX = exe

all:	liblaminarchaos.lib

endif


ALLOBJECTS = MD2Mesh.$(OBJPOSTFIX) material.$(OBJPOSTFIX)  md2.$(OBJPOSTFIX) \
   mesh.$(OBJPOSTFIX) model.$(OBJPOSTFIX) modelframe.$(OBJPOSTFIX) \
   MD2MeshImpl.$(OBJPOSTFIX) TickCount.$(OBJPOSTFIX)

liblaminarchaos.a:	$(ALLOBJECTS)
	ar -r liblaminarchaos.a $(ALLOBJECTS)

liblaminarchaos.lib:  $(ALLOBJECTS)
	link /lib /out:liblaminarchaos.lib $(ALLOBJECTS)

ifeq ($(MSVC),1)
testlaminarchaos:	testlaminarchaos.exe
	

testlaminarchaos.$(EXESUFFIX):	$(ALLOBJECTS) testlaminarchaos.obj
	cl /Fetestlaminarchaos.exe $(ALLOBJECTS) testlaminarchaos.obj libtartan.lib
endif

ifeq ($(LINUX),1)
testlaminarchaos.$(EXESUFFIX):	$(ALLOBJECTS) testlaminarchaos.obj
	g++ -out:testlaminarchaos.exe $(ALLOBJECTS) testlaminarchaos.obj libtartan.a
endif

testlaminarchaos.$(OBJPOSTFIX):	testlaminarchaos.cpp MD2Mesh.h
	$(C++) testlaminarchaos.cpp
	
MD2Mesh.$(OBJPOSTFIX):	MD2Mesh.cpp MD2Mesh.h
	$(C++) MD2Mesh.cpp
	
MD2MeshImpl.$(OBJPOSTFIX):	MD2MeshImpl.cpp MD2MeshImpl.h MD2Mesh.h
	$(C++) MD2MeshImpl.cpp
	
material.$(OBJPOSTFIX):	material.cpp material.h
	$(C++) material.cpp
	
md2.$(OBJPOSTFIX):	md2.cpp md2.h
	$(C++) md2.cpp
	
mesh.$(OBJPOSTFIX):	mesh.cpp mesh.h
	$(C++) mesh.cpp
	
model.$(OBJPOSTFIX):	model.cpp model.h
	$(C++) model.cpp
	
ModelFactory.$(OBJPOSTFIX):	ModelFactory.cpp ModelFactory.h ModelFactoryInterface.h
	$(C++) ModelFactory.cpp
	
modelframe.$(OBJPOSTFIX):	modelframe.cpp modelframe.h
	$(C++) modelframe.cpp
	
TickCount.$(OBJPOSTFIX):	TickCount.cpp TickCount.h
	$(C++) TickCount.cpp


