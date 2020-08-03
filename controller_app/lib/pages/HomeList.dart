import 'package:flutter/material.dart';

class HomeList extends StatefulWidget {
  @override
  _HomeListState createState() => _HomeListState();

}

class _HomeListState extends State<HomeList>{
  @override
  Widget build(BuildContext context){
    return ListView(
      shrinkWrap: true,
      children: <Widget>[
        ListTile(
          leading: Icon(Icons.pages),
          title: Text('First'),
          trailing: Icon(Icons.settings),
        )
      ],
    );
  }
}