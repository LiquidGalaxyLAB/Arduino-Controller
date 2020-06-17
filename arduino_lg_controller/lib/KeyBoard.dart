import 'dart:ffi';

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
            Container(height: 4,color: Colors.white,),
            Expanded(
              child: Container(
                child: LayoutBuilder(
                  builder: (_,constraints) {
                    return Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: <Widget>[
                        Container(
                          width: 0.02,
                          height: constraints.maxHeight ,
                          color: Colors.white,
                        ),
                        Container(
                          width: constraints.maxWidth*.63,
                          height: constraints.maxHeight,
                          color: Colors.blue,
                          child: ListView(
                            children: <Widget>[
                              Container(
                                height: 50,
                                child: Center(child: Text("Insert the places you want to navigate")),
                              ),
                              Container(
                                color: Colors.grey,
                                width: size.width,
                                height: 4,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    fontSize: 20,
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
                                    color: Colors.white,
                                    width: size.width,
                                    child: IconButton(icon: Icon(Icons.file_download,color: Colors.blue,size: 35,), onPressed: (){}),
                                  ),
                                  Container(
                                    color: Colors.grey,
                                    width: size.width,
                                    height: 3,
                                  ),
                                  Container(
                                    child: IconButton(icon: Icon(Icons.file_upload,color: Colors.blue,size: 35,), onPressed: (){}),
                                  ),
                                  Container(
                                    color: Colors.grey,
                                    width: size.width,
                                    height: 3,
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
            Container(height: 4,color: Colors.white,)
          ],
        ),
        ),
    );
  }
}