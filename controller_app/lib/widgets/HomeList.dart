import 'package:flutter/material.dart';

class HomeList extends StatefulWidget {

  static List<Widget> items = List<Widget>();
  @override
  _HomeListState createState() => _HomeListState();
}

class _HomeListState extends State<HomeList>{
  @override
  Widget build(BuildContext context){

    List<Widget> values = List<Widget>();
    if(HomeList.items.length == 0){
      values.add(ListTile(
        leading: Icon(Icons.pages),
        title: Text('No Lists'),
        trailing: Icon(Icons.settings_applications),
      ));
    }

    return ListView(
      shrinkWrap: true,
      children: (HomeList.items.length == 0) ? values : HomeList.items
    );
  }
}