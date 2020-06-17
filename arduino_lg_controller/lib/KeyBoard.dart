import 'dart:ffi';
import 'dart:ui';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class KeyBoardPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var appBar = AppBar(title: Text("KeyBoard Places"));
    var size = MediaQuery.of(context).size;

    return Scaffold(
      appBar: appBar,
      body: Container(
        width: size.width,
        height: size.height,
        child: Column(
          children: <Widget>[
            Container(height: 8,color: Colors.white,),
            Expanded(
              child: Container(
                child: LayoutBuilder(
                  builder: (_,constraints) {
                    return Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: <Widget>[
                        Container(
                          width: 0.03,
                          height: constraints.maxHeight ,
                          color: Colors.white,
                        ),
                        Container(
                          width: constraints.maxWidth*.62,
                          height: constraints.maxHeight,
                          color: Colors.blue,
                          child: ListView(
                            children: <Widget>[
                              Container(
                                height: constraints.maxHeight* .1,
                                child: Center(
                                    child: Text("Insert the places you want to navigate",textAlign: TextAlign.center,
                                    style: TextStyle(
                                      color: Colors.white,fontSize: 18,fontWeight: FontWeight.w700,
                                    ),
                                    )),
                              ),
                              Container(
                                color: Colors.white30,
                                width: size.width,
                                height: 10,
                              ),
                              //Divider(
                                //height: 3,
                                //color: Colors.white,
                             // ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 1",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 2",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 3",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 4",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 5",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 6",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 7",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 8",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 9",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 10",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 11",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 12",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 13",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 14",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 15",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                              TextFormField(
                                keyboardType: TextInputType.text,
                                decoration: InputDecoration(
                                  labelText: "Place 16",
                                  labelStyle: TextStyle(
                                    color: Colors.white,
                                    fontWeight: FontWeight.w400,
                                    fontSize: 15,
                                  ),
                                ),

                              ),
                              Divider(
                                height: 3,
                                color: Colors.white,
                              ),
                            ],
                          ),
                        ),
                        Container(
                          width: constraints.maxWidth*.35,
                          height: constraints.maxHeight ,
                          color: Colors.white,
                          child: LayoutBuilder(
                            builder: (_,constraints){
                              return Column(
                                children: <Widget>[
                                  Container(
                                    child: Column(
                                      children: <Widget>[
                                        Container(
                                          child: SizedBox(
                                            child: RaisedButton(
                                              onPressed: (){

                                              },
                                              child: Text("Send", style: TextStyle(
                                                    color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                              ),
                                              color: Colors.blue,
                                              elevation: 10,
                                            ),
                                          ),
                                          width: constraints.maxWidth*.85,
                                          height: constraints.maxHeight* .1,
                                        ),

                                        Container(
                                          color: Colors.white,
                                          width: size.width,
                                          height: 10,
                                        ),
                                        Container(
                                          child: SizedBox(
                                            child: RaisedButton(
                                              onPressed: (){

                                              },
                                              child: Text("Get", style: TextStyle(
                                                  color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                              ),
                                              color: Colors.blue,
                                              elevation: 10,
                                            ),
                                          ),
                                          width: constraints.maxWidth*.85,
                                          height: constraints.maxHeight* .1,
                                        )
                                      ],
                                    ),
                                  )
                                ],
                              );
                            },
                          ),
                          //child: IconButton(icon: Icon(Icons.send,color: Colors.blue,size: 35,), onPressed: (){}),
                        )
                      ],
                    );
                  },
                ),
              ),
            ),
            Container(height: 8,color: Colors.white,)
          ],
        ),
        ),
    );
  }
}