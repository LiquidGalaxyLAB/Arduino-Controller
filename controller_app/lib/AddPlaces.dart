import 'dart:ui';
import 'package:controllerapp/main.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';
import 'package:flutter_slidable/flutter_slidable.dart';

String coordenada;
List<String> _list = List();
int listIndex;

class AddPlace extends StatelessWidget {
  final TextEditingController textEditingController  = new TextEditingController();
  final TextEditingController textEditingControllerLo  = new TextEditingController();
  final TextEditingController textEditingControllerLa  = new TextEditingController();
  final TextEditingController textEditingControllerRa  = new TextEditingController();
  //List<String> _list = List();


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
              color: Colors.white,
              child: Center(
                  child: Text("Insert the places you want to navigate",textAlign: TextAlign.center,
                    style: TextStyle(
                      color: Colors.blue,fontSize: 18,fontWeight: FontWeight.w700,
                    ),
                  )),
            ),
            Container(
              alignment: Alignment.topLeft,
              width: size.width,
              height: 60 ,
              color: Colors.white,
              child: LayoutBuilder(
                builder: (_,constraints){
                  return Row(
                    children: <Widget>[
                      //Padding(padding: EdgeInsets.only(right: 50)),
                      Container(
                        width: constraints.maxWidth*.20,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){
                              showDialog(
                                  context: context,
                                  barrierDismissible: true,
                                  builder: (BuildContext context){
                                    return AlertDialog(
                                      title: Text('Delete'),
                                      content: Text('If you click delete the list will be deleted and cannot be recovered'),
                                      actions: <Widget>[
                                        RaisedButton(
                                          color: Colors.green,
                                          child: Text('Cancel'),
                                          onPressed: (){
                                            Navigator.of(context).pop();
                                          },
                                        ),
                                        RaisedButton(
                                          color: Colors.red,
                                          child: Text('Delete'),
                                          onPressed: (){
                                            var end = _list.length;
                                            _list.removeRange(0,end);
                                            Navigator.of(context).pop();
                                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>AddPlace()));
                                          },
                                        )
                                      ],
                                    );
                                  }
                              );
                            },
                            child: Text("Delete", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.red,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.25,
                        height: constraints.maxHeight*.70,
                        alignment: Alignment.topCenter,
                      ),
                      Container(
                        width: constraints.maxWidth*.02,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){ },
                            child: Text("Save", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.green,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.25,
                        height: constraints.maxHeight*.70,
                        alignment: Alignment.topCenter,
                      ),
                      Container(
                        width: constraints.maxWidth*.02,
                        height: constraints.maxHeight*.80,
                      ),
                      Container(
                        child: SizedBox(
                          child: RaisedButton(
                            onPressed: (){
                              showDialog(
                                  context: context,
                                  barrierDismissible:false,
                                  builder: (BuildContext context){
                                    return AlertDialog(
                                      title: Text('Add Places'),
                                      content: SingleChildScrollView(
                                        child: ListBody(
                                          children: <Widget>[
                                            TextFormField(
                                              keyboardType: TextInputType.text,
                                              controller: textEditingController,
                                              validator:(value){
                                                if(value.trim().isEmpty){
                                                  return 'Task field it\'s required';
                                                }
                                                return null;
                                              },
                                              decoration: InputDecoration(
                                                  hintText: "Place Name",
                                                  contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                  border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                              ),
                                            ),
                                            Container(height:10,),
                                            TextFormField(
                                              keyboardType: TextInputType.number,
                                              controller: textEditingControllerLo,
                                              validator:(value){
                                                if(value.trim().isEmpty){
                                                  return 'Task field it\'s required';
                                                }
                                                return null;
                                              },
                                              decoration: InputDecoration(
                                                  hintText: "Longitude",
                                                  contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                  border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                              ),
                                            ),
                                            Container(height:10,),
                                            TextFormField(
                                              keyboardType: TextInputType.number,
                                              controller: textEditingControllerLa,
                                              validator:(value){
                                                if(value.trim().isEmpty){
                                                  return 'Task field it\'s required';
                                                }
                                                return null;
                                              },
                                              decoration: InputDecoration(
                                                  hintText: "Latitude",
                                                  contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                  border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                              ),
                                            ),
                                            Container(height:10,),
                                            TextFormField(
                                              keyboardType: TextInputType.number,
                                              controller: textEditingControllerRa,
                                              decoration: InputDecoration(
                                                  hintText: "Range",
                                                  contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                  border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                              ),
                                            )
                                          ],
                                        ),
                                      ),
                                      actions: <Widget>[
                                        RaisedButton(
                                          color:Colors.green,
                                          child: Text('Cancel'),
                                          onPressed: (){Navigator.of(context).pop();},
                                        ),
                                        RaisedButton(
                                          color:Colors.blue,
                                          child: Text('Add'),
                                          onPressed: (){
                                            _list.add(textEditingController.text+':  '+textEditingControllerLo.text +'-'+textEditingControllerLa.text+'-'+textEditingControllerRa.text);
                                            _closeInput();
                                            Navigator.of(context).pop();},
                                        )
                                      ],
                                    );
                                  }
                              );
                            },
                            child: Text("Add", style: TextStyle(
                                color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                            ),
                            color: Colors.blue,
                            elevation: 10,
                          ),
                        ),
                        width: constraints.maxWidth*.25,
                        height: constraints.maxHeight*.70,
                        alignment: Alignment.topCenter,
                      ),
                    ],
                  );
                },
              ),
            ),
            Expanded(
              child: Container(
                child: ListView.builder(
                  itemCount: _list.length,
                  itemBuilder: (context, index){
                    return Card(
                      child: Slidable(
                        actionPane: SlidableDrawerActionPane(),
                        actionExtentRatio: 0.25,
                        child: ListTile(
                          leading: CircleAvatar(
                            backgroundColor: Colors.green,
                            child: Text("$index"),
                            foregroundColor: Colors.white,
                          ),
                          title: Text(_list[index]),
                          onTap: (){
                            showDialog(
                                context: context,
                                barrierDismissible:false,
                                builder: (BuildContext context){
                                  return AlertDialog(
                                    title: Text('Edit Places'),
                                    content: SingleChildScrollView(
                                      child: ListBody(
                                        children: <Widget>[
                                          TextFormField(
                                            keyboardType: TextInputType.text,
                                            controller: textEditingController,
                                            validator:(value){
                                              if(value.trim().isEmpty){
                                                return 'Task field it\'s required';
                                              }
                                              return null;
                                            },
                                            decoration: InputDecoration(
                                                hintText: "Place Name",
                                                contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                            ),
                                          ),
                                          Container(height:10,),
                                          TextFormField(
                                            keyboardType: TextInputType.number,
                                            controller: textEditingControllerLo,
                                            validator:(value){
                                              if(value.trim().isEmpty){
                                                return 'Task field it\'s required';
                                              }
                                              return null;
                                            },
                                            decoration: InputDecoration(
                                                hintText: "Longitude",
                                                contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                            ),
                                          ),
                                          Container(height:10,),
                                          TextFormField(
                                            keyboardType: TextInputType.number,
                                            controller: textEditingControllerLa,
                                            validator:(value){
                                              if(value.trim().isEmpty){
                                                return 'Task field it\'s required';
                                              }
                                              return null;
                                            },
                                            decoration: InputDecoration(
                                                hintText: "Latitude",
                                                contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                            ),
                                          ),
                                          Container(height:10,),
                                          TextFormField(
                                            keyboardType: TextInputType.number,
                                            controller: textEditingControllerRa,
                                            decoration: InputDecoration(
                                                hintText: "Range",
                                                contentPadding: EdgeInsets.fromLTRB(20, 10, 20, 10),
                                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                                            ),
                                          )
                                        ],
                                      ),
                                    ),
                                    actions: <Widget>[
                                      RaisedButton(
                                        color:Colors.green,
                                        child: Text('Cancel'),
                                        onPressed: (){Navigator.of(context).pop();},
                                      ),
                                      RaisedButton(
                                        color:Colors.blue,
                                        child: Text('Save'),
                                        onPressed: (){
                                          //_list.add(textEditingController.text+':  '+textEditingControllerLo.text +'-'+textEditingControllerLa.text+'-'+textEditingControllerRa.text);
                                          //_list.removeAt(index);
                                          _closeInput();
                                          Navigator.of(context).pop();},
                                      )
                                    ],
                                  );
                                }
                            );
                          }, // Adicionar Campo Editar
                        ),
                        secondaryActions: <Widget>[
                          IconSlideAction(
                            caption: 'Delete',
                            color: Colors.red,
                            icon: Icons.delete_forever,
                            onTap: () {
                              showDialog(
                                context: context,
                                barrierDismissible: true,
                                builder: (BuildContext context){
                                  return AlertDialog(
                                    title: Text('Delete'),
                                    content: Text('If you click delete the file will be deleted and cannot be recovered'),
                                    actions: <Widget>[
                                      RaisedButton(
                                        color: Colors.green,
                                        child: Text('Cancel'),
                                        onPressed: (){
                                          Navigator.of(context).pop();
                                        },
                                      ),
                                      RaisedButton(
                                        color: Colors.red,
                                        child: Text('Delete'),
                                        onPressed: (){
                                          _list.removeAt(index);
                                          Navigator.of(context).pop();
                                          Navigator.of(context).push(MaterialPageRoute(builder: (context)=>AddPlace()));
                                        },
                                      )
                                    ],
                                  );
                                }
                              );
                            },
                          )
                        ],
                      ),
                    );
                  },
                ),
                ),
              //),
            //Container(height: 8,color: Colors.white,)
            )
          ],
        ),
      ),
    );
  }
  void _closeInput () async{
    textEditingController .clear();
    textEditingControllerLo.clear();
    textEditingControllerLa.clear();
    textEditingControllerRa.clear();
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

