from django.http import HttpResponse
from django.shortcuts import render

def django(request):
    return render(request, 'templates/base.html', {'id_page': 0, 'title_page': "Ex01 : Django, framework web."})
def affichage(request):
    return render(request, 'templates/base.html', {'id_page': 1, 'title_page': "Ex01 : Processus d’affichage d’une page statique."})
def templates(request):
    return render(request, 'templates/base.html', {'id_page': 2, 'title_page': "Ex01 : Moteur de template."})