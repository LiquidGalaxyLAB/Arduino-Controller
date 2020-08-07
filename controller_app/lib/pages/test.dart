import 'package:flutter/material.dart';

class futlista extends StatefulWidget {
  final String continent;

  const futlista({Key key, this.continent}) : super(key: key);
  @override
  _futlistaState createState() => _futlistaState();
}


class _futlistaState extends State<futlista> {
  @override
  Widget build(BuildContext context) {
    return Container(
      color: Colors.black87,
      child: Text(widget.continent),

    );
  }
}

