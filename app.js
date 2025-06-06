const express = require('express');
const morgan = require('morgan');
const mongoose = require('mongoose');
const blogRoutes = require('./routes/blogRoutes');
const port = 3000;

// express app
const app = express();

// connect to mongodb & listen for requests
const dbURI = "mongodb+srv://suryanshg10:qwerty123@nodejs.2f3e7ph.mongodb.net/?retryWrites=true&w=majority&appName=nodejs";

mongoose.connect(dbURI)
  .then(console.log("success"))
  .catch(err => console.log(err));


app.listen(port, ()=>{
    console.log("listening on port" + port);
})


// register view engine
app.set('view engine', 'ejs');

// middleware & static files
app.use(express.static('public'));
app.use(express.urlencoded({ extended: true }));
app.use(morgan('dev'));
app.use((req, res, next) => {
  res.locals.path = req.path;
  next();
});

// routes
app.get('/', (req, res) => {
  res.redirect('/blogs');
});

app.get('/about', (req, res) => {
  res.render('about', { title: 'About' });
});

// blog routes
app.use('/blogs',blogRoutes);

// 404 page
app.use((req, res) => {
  res.status(404).render('404', { title: '404' });
});