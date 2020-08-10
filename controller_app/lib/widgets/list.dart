import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';


class ListPage extends StatefulWidget {

  static final tag = 'list-page';
  @override
  _ListPageState createState() => _ListPageState();
}

class _ListPageState extends State<ListPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('teste'),
      ),
    );
  }
}
