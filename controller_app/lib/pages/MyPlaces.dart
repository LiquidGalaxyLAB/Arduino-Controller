import 'dart:ui';
import 'package:controllerapp/widgets/HomeList.dart';
import 'package:controllerapp/widgets/list.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class MyPlaces extends StatefulWidget {
  static final tag = 'myplaces-page';
  @override
  _MyPlacesState createState() => _MyPlacesState();
}

class _MyPlacesState extends State<MyPlaces> {
  final TextEditingController _c  = new TextEditingController();
  var appBar = AppBar(title: Text("My Places"));
  final _formKey = GlobalKey<FormState>();


  @override
  Widget build(BuildContext context) {

    var size = MediaQuery.of(context).size;
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
              height: 60,
              color: Colors.white,
              child: Center(
                  child: Text("Create a new list to insert your 16 favorite places",textAlign: TextAlign.center,
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
                      Container(width: constraints.maxWidth*.38,),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){
                              showDialog(
                                  context: context,
                                  barrierDismissible: false,
                                  builder: (BuildContext ctx){
                                    return Form(
                                        key: _formKey,
                                        child: AlertDialog(
                                          title: Text('New List'),
                                          content: SingleChildScrollView(
                                            child: ListBody(
                                              children: <Widget>[
                                                TextFormField(
                                                  validator: (value){
                                                    if(value.isEmpty) return "The list name is mandatory";
                                                    return null;
                                                  },
                                                  controller: _c,
                                                  decoration: InputDecoration(
                                                      hintText: 'List Name',
                                                      contentPadding: EdgeInsets.fromLTRB(20, 10,20, 10),
                                                      border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                                  ),
                                                )
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
                                                  if(_formKey.currentState.validate())
                                                  {
                                                    HomeList.items.add(
                                                        ListTile(
                                                          leading: Icon(Icons.pages),
                                                          title: Text(_c.text),
                                                          trailing: Icon(Icons.send),
                                                          onTap:(){
                                                            print(HomeList.items);
                                                                Navigator.of(context).pushNamed(ListPage.tag);
                                                              }
                                                        )
                                                    );
                                                    _c.clear();
                                                    Navigator.of(ctx).pop();
                                                    //Navigator.of(context).pushNamed(MyPlaces.tag);
                                                    Navigator.of(context).push(MaterialPageRoute(builder: (context)=>MyPlaces()));
                                                    //Navigator.of(context).popAndPushNamed(MyPlaces.tag);
                                                   // Navigator.pushReplacement(context, MaterialPageRoute(builder: (BuildContext context) => MyPlaces()));
                                                    //Navigator.of(context).pushReplacement(MaterialPageRoute(builder: (context)=>MyPlaces()));
                                                  }
                                                }
                                            )
                                          ],
                                        )
                                    ) ;
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
            Container( height: 10),
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
