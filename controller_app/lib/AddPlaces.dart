import 'dart:ui';
import 'package:controllerapp/main.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

String coordenada;

class AddPlace extends StatelessWidget {
  final TextEditingController textEditingController  = new TextEditingController();
  final TextEditingController textEditingControllerLo  = new TextEditingController();
  final TextEditingController textEditingControllerLa  = new TextEditingController();
  final TextEditingController textEditingControllerRa  = new TextEditingController();
  @override
  Widget build(BuildContext context) {
    var appBar = AppBar(title: Text("List PLaces"));
    var size = MediaQuery.of(context).size;
    String local;
    return Scaffold(
      appBar: appBar,
      body: Container(
        width: size.width,
        height: size.height,
        child: Column(
          children: <Widget>[
            Container(height: 2,color: Colors.white,),
            Container(
              width: size.width,
              height: 40,
              child: Center(
                  child: Text("Insert the places you want to navigate",textAlign: TextAlign.center,
                    style: TextStyle(
                      color: Colors.blue,fontSize: 20,fontWeight: FontWeight.w700,
                    ),
                  )),
            ),
            Container(
              width: size.width,
              height: 60 ,
              color: Colors.white,
              child: LayoutBuilder(
                builder: (_,constraints){
                  return Row(
                    children: <Widget>[
                      Container(
                        width: constraints.maxWidth*.02,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){_sendMessage(textEditingController.text);},
                            child: Text("Send", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.blue,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.25,
                        height: constraints.maxHeight*.70,
                      ),
                      Container(
                        width: constraints.maxWidth*.02,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){ },
                            child: Text("Get", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.blue,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.25,
                        height: constraints.maxHeight*.70,
                      ),
                      Container(
                        width: constraints.maxWidth*.02,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){ },
                            child: Text("Examples", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.blue,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.41,
                        height: constraints.maxHeight*.70,
                      )
                    ],
                  );
                },
              ),
              //child: IconButton(icon: Icon(Icons.send,color: Colors.blue,size: 35,), onPressed: (){}),
            ),
            Container(
              width: size.width*.95,
              height: 225,
              color: Colors.blue,
              child: LayoutBuilder(
                builder: (_,consttrainsts){
                  return Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: <Widget>[
                      Container(
                        child: new TextFormField(
                          keyboardType: TextInputType.text,
                          controller: textEditingController,
                          decoration: InputDecoration(
                            labelText: "Place",
                            labelStyle: TextStyle(color: Colors.white,fontWeight: FontWeight.w400,fontSize: 12,),
                          ),
                        ),
                      ),
                      Container(
                        child:
                        TextFormField(
                          keyboardType: TextInputType.phone,
                          controller: textEditingControllerLo,
                          decoration: InputDecoration(
                            labelText: "Longitude",
                            labelStyle: TextStyle(color: Colors.white,fontWeight: FontWeight.w400,fontSize: 12,),
                          ),
                        ),
                      ),

                      Container(
                        child:
                        TextFormField(
                          keyboardType: TextInputType.phone,
                          controller: textEditingControllerLa,
                          decoration: InputDecoration(
                            labelText: "Latitude",
                            labelStyle: TextStyle(color: Colors.white,fontWeight: FontWeight.w400,fontSize: 12,),
                          ),
                        ),

                      ),

                      Container(
                        child:
                        TextFormField(
                          keyboardType: TextInputType.phone,
                          controller: textEditingControllerRa,
                          decoration: InputDecoration(
                            labelText: "Range",
                            labelStyle: TextStyle(color: Colors.white,fontWeight: FontWeight.w400,fontSize: 12,),
                          ),
                        ),

                      ),
                    ],
                  );
                },
              ),
            ),
            Expanded(
              child: Container(
                child: LayoutBuilder(
                  builder: (_,constraints) {
                    return Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: <Widget>[
                        Container(
                          width: constraints.maxWidth*.95,
                          height: constraints.maxHeight*.9,
                          color: Colors.green,
                          child: ListView(
                            children: <Widget>[
                              ListTile(
                                title: Text(textEditingController.text + '-'+
                                    textEditingControllerLo.text + ','+
                                    textEditingControllerLa.text + ','+
                                    textEditingControllerRa.text ),
                              ),
                            ],
                          ),
                        ),
                      ],
                    );
                  },
                ),
              ),
            ),
            //Container(height: 8,color: Colors.white,)
          ],
        ),
      ),
    );
  }
  void _sendMessage (String text) async{
    textEditingController .clear();
    textEditingControllerLo.clear();
    textEditingControllerLa.clear();
    textEditingControllerRa.clear();
    text = text.trim();
    variavel = text;
    debugPrint(text);
    //Future.delayed(Duration(milliseconds: 333)).then((_) {
    //  listScrollController.animateTo(
    //     listScrollController.position.maxScrollExtent,
    //     duration: Duration(milliseconds: 333),
    //    curve: Curves.easeOut);
    // });
  }
}

