from django.http import HttpResponse
from django.shortcuts import render

def Markdown(request):
    return render(request, 'templates/index.html', context={})