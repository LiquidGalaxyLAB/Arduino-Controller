import 'dart:ui';
import 'package:controllerapp/main.dart';
import 'package:controllerapp/pages/HomeList.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

String coordenada;

class KeyBoardPage extends StatelessWidget {
  final TextEditingController _c  = new TextEditingController();
  @override
  Widget build(BuildContext context) {
    var appBar = AppBar(title: Text("KeyBoard Places"));
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
              color: Colors.white,
              child: Center(
                  child: Text("Insert the places you want to navigate",textAlign: TextAlign.center,
                    style: TextStyle(
                      color: Colors.blue,fontSize: 18,fontWeight: FontWeight.w700,
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
                        width: constraints.maxWidth*.38,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){
                              showDialog(
                                  context: context,
                                barrierDismissible: false,
                                builder: (BuildContext ctx){
                                    final input = TextFormField(
                                      controller: _c,
                                      decoration: InputDecoration(
                                        hintText: 'List Name',
                                        contentPadding: EdgeInsets.fromLTRB(20, 10,20, 10),
                                        border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                      ),
                                    );
                                    return AlertDialog(
                                      title: Text('New List'),
                                      content: SingleChildScrollView(
                                        child: ListBody(
                                          children: <Widget>[
                                            input
                                          ],
                                        ),
                                      ),
                                      actions: <Widget>[
                                        RaisedButton(
                                          color: Colors.green,
                                            child: Text('Cancel'),
                                            onPressed: (){
                                            _c.clear();
                                            Navigator.of(ctx).pop();
                                            }
                                        ),
                                        RaisedButton(
                                            color: Colors.blue,
                                            child: Text('Add'),
                                            onPressed: (){
                                              _c.clear();
                                              Navigator.of(ctx).pop();
                                            }
                                        )
                                      ],
                                    );
                                }
                              );
                            },
                            child: Text("Add New List", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.blue,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.60,
                        height: constraints.maxHeight*.70,
                      )
                    ],
                  );
                },
              ),
              //child: IconButton(icon: Icon(Icons.send,color: Colors.blue,size: 35,), onPressed: (){}),
            ),
            Container(
              width: 20,
              height: 10,
            ),
            Expanded(
              child: Container(
                width: size.width*.96,
                color: Colors.white,
                child: LayoutBuilder(
                    builder: (_,constraints){
                      return HomeList();
                    }
                ),
              ),
            ),
            //Container(height: 8,color: Colors.white,)
          ],
        ),
      ),
    );
  }
}

void _sendMessage (String text) async{
  text = text.trim();
  variavel = text;
  debugPrint(text);
}
